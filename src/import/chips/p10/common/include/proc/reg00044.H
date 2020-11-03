/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00044.H $         */
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

#ifndef __PROC_REG00044_H_
#define __PROC_REG00044_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPCHIP_TPC_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_LOCAL_FIR_RW]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_RW]

//>> PUT_[TP_TPCHIP_TPC_LOCAL_FIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_LOCAL_FIR_RW]

//>> PREP_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]

//>> PUT_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_LOCAL_FIR_WO_AND]

//>> PREP_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_TPC_LOCAL_FIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]

//>> PUT_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_TPC_LOCAL_FIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_TPC_LOCAL_FIR_WO_OR]


//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CFIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CFIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CFIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CFIR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CFIR]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CPLT_CTRL]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_PCB]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_CC_OTHERS]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN04]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN05]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN06]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN07]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN08]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN09]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN10]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN11]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN12]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN13]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN14]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN15]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN16]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN17]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN18]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN19]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN20]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN21]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN22]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN23]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN24]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN25]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN26]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN27]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN28]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN29]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN30]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN31]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN32]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN33]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN34]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN35]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN36]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN37]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN38]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN39]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN40]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN41]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN42]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN43]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN44]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN45]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN46]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN47]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN48]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN49]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN50]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN51]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN52]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN53]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN54]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN55]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN56]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN57]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN58]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN59]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN60]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN61]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_IN62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_IN62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_IN62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_IN62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_IN62]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.setBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> GET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]
static inline bool GET_TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_TPC_LOCAL_FIR_RW, TP_TPCHIP_TPC_LOCAL_FIR_WO_AND, TP_TPCHIP_TPC_LOCAL_FIR_WO_OR));
#endif
    return i_data.getBit<TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_TPC_LOCAL_FIR_EXT_LOCAL_XSTOP]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI]

//>> PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]
static inline bool GET_TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI, TP_TPVSB_FSI_W_FSI2PIB_RESET_FSI_BYTE));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_FSI2PIB_RESET_RESET]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE]

//>> PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]

//>> PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO]


//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RESET_EP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE,
           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.setBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return o_data.clearBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]
static inline bool GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI,
                           TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE, TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_RO));
#endif
    return i_data.getBit<TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI]

//>> PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]

//>> PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE(
    const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return fapi2::putScom(i_target, TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE]


//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]

//>> SET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return o_data.insertFromRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]

//>> GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI,
                           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_FSI_BYTE));
#endif
    return i_data.extractToRight<TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG,
           TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPVSB_FSI_W_SHIFT_DMA_STAT_COMP_MASK_REGISTER_DMA_STAT_COMP_MASK_REG]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
