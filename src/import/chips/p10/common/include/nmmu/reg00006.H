/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/nmmu/reg00006.H $         */
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

#ifndef __NMMU_REG00006_H_
#define __NMMU_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace nmmu
{
#endif


//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND]

//>> PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]

//>> PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR]


//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBI_PE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_CMD_HANG_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_READ_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_WRITE_ARE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_MISC_HW_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RSVD_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_XLAT_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_LCO_ARRAY_ECC_SUE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_CE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INBD_ARRAY_ECC_UE_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_INT_STATE_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LOAD_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_STORE_LINK_ERR_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]

//>> SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline fapi2::buffer<uint64_t>& SET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.setBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]

//>> CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline fapi2::buffer<uint64_t>& CLEAR_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline fapi2::buffer<uint64_t>& GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]

//>> GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]
static inline bool GET_FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_RW, FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_AND,
                           FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_WO_OR));
#endif
    return i_data.getBit<FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_nmmu Invalid dial access FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_REG_PBUS_LINK_ABORT_FIR]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
