/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00012.H $         */
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

#ifndef __PROC_REG00012_H_
#define __PROC_REG00012_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PSIHB_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_FIR_ACTION1_REG]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG]

//>> PUT_[TP_TPBR_PSIHB_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_FIR_ACTION1_REG]


//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_ECC_ERR_SUE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_FROM_FSP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_CE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ECC_ERR_UE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_ERROR_STATE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_TTYPE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INVALID_CRESP_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_DATA_TIME_OUT_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_PB_PARITY_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FSP_ACCESS_TRUSTED_SPACE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UNEXPECTED_PB_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT_REG_CHANGE_WHILE_ACTIVE_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT0_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT1_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT2_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT3_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT4_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_INTERRUPT5_ADDRESS_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_0_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_TCBR_TP_PSI_GLB_ERR_1_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_UPSTREAM_FIR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1,
           TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1,
           TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1,
           TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_SPARE_FIR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]
static inline bool GET_TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_FIR_ACTION1_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_FIR_ACTION1_REG_FIR_PARITY_ERROR_ACTION1]

//>> PREP_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_ERROR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_ERROR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ERRORS]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_ERROR_REG_QME_FSM_ERROR]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_ERROR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_ERROR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ERRORS]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INT_TYPE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CL_DATA_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_INFO_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_SEQ_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR,
           TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_ERROR_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_ERROR_REG_QME_FSM_ERROR]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_HANG_PULSE_REG_0]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_0_REG_SUPPRESS_HANG_0]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_HANG_PULSE_REG_1]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_1_REG_SUPPRESS_HANG_1]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_HANG_PULSE_REG_2]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_2_REG_SUPPRESS_HANG_2]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_HANG_PULSE_REG_3]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_3_REG_SUPPRESS_HANG_3]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_HANG_PULSE_REG_4]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_4_REG_SUPPRESS_HANG_4]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_HANG_PULSE_REG_5]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_5_REG_SUPPRESS_HANG_5]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6,
           TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_HANG_PULSE_REG_6]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]
static inline bool GET_TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_HANG_PULSE_6_REG_SUPPRESS_HANG_6]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT,
           TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]

//>> SET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT,
           TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT,
           TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_TIMEOUT_REG_INT_TIMEOUT]

//>> PREP_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]

//>> GET_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]

//>> PUT_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN1_VITAL_SCAN_OUT]


//>> PREP_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG(const fapi2::Target<K, M, V>&
        i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]

//>> PUT_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG]


//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]
static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_ATTN]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]
static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_RECOV]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]
static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_XSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]
static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_LXSTOP]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.setBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return o_data.clearBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]
static inline bool GET_TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG));
#endif
    return i_data.getBit<TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLPERV_ASSIST_INTERRUPT_REG_TYPE4]

//>> PREP_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]

//>> GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]

//>> PUT_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV]


//>> SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]

//>> SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]

//>> GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION,
           TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_ARB_OCB_PIB_OREV_OCI_ARB_REVISION]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR1_OCB_OCI_GPEXIVDR0_GPR1]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_MEMORY_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEML_OCB_OCI_GPEXIMEM_MEM_DATAOP_PENDING]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIMEMU_OCB_OCI_GPEXIMEM_MEM_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISRR0_OCB_OCI_GPEXIDBGINF_SRR0]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIVDR0_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEOXIXCR_OCB_OCI_GPEOXIXCR_XCR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_LINE2_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIICAC_ICACHE_PREFETCH_PENDING]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIRAMEDR_EDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIGPR5_OCB_OCI_GPEXIVDR4_GPR5]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_R_NW]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BUSY]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_BYTE_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_LINE_MODE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_ERROR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIMEM_DATAOP_PENDING]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_OCB_OCI_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMGA_SPRG0]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_4]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR4_5]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_CR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_CR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_FRAME_SIZE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_OUT_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_DELAY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_CR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_CR0_IN_COUNT]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_7]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_8]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9,
           TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_ADC_RDATA4_9]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_DORP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_DORP1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_DORP1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_DORP1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_DORP1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_DORP1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_DORP1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_DORP1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_DORP1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_DORP1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_DORP1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_QUOTIENT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_DORP1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER,
           TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_DORP1_REMAINDER]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G0ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G0ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G0ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G0ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G0ISR1_INTERRUPT_GPE0_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G1ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G1ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G1ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G1ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G1ISR1_INTERRUPT_GPE1_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G2ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G2ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G2ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G2ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G2ISR1_INTERRUPT_GPE2_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_G3ISR1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_G3ISR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_G3ISR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_G3ISR1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1,
           TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_G3ISR1_INTERRUPT_GPE3_STATUS_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRL21_OCB_OCI_O2SCTRL21_O2S_INTER_FRAME_DELAY_1]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_OUT_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_DELAY2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLS0_IN_COUNT2_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST1A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SST1A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST1A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SST1A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SST1A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ONGOING_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4,
           TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_1_4]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_WRITE_WHILE_BRIDGE_BUSY_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_ST1A_RESERVED_6]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SST1A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SST1A_FSM_ERR_1A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_OCI_REGION]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3_START]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_FULL]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_EMPTY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_LENGTH]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_WRITE_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR,
           TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_READ_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2_PUSH_ENABLE]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSHI1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHI1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSHI1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSHI1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHI1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSHI1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSHI1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSHI1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSHI1]


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSLI3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLI3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSLI3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSLI3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLI3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSLI3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSLI3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSLI3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSLI3]


//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_RW, TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS,
           TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCFLG4_OCB_OCI_OCCFLG4_OCC_FLAGS]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCMISC(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCMISC(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_CORE_EXT_INTR]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_EXT_INTR_REASON]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_GROSS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_FINE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_FAULT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_FIRMWARE_NOTIFY]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_SPARE]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCMISC, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS,
           TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCMISC_I2CM_INTR_STATUS]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q1RR_OCB_OCI_OPIT0Q1RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT0Q3_OCB_OCI_OPIT0Q3RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT1Q1RR_OCB_OCI_OPIT1Q1RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT2Q1RR_OCB_OCI_OPIT2Q1RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q1RR_OCB_OCI_OPIT3Q1RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT3Q7_OCB_OCI_OPIT3Q7RR_PCB_INTR_PAYLOAD]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD,
           TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OPIT4Q1_OCB_OCI_OPIT4Q1RR_PCB_INTR_PAYLOAD]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
