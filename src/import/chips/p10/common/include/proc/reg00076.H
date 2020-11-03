/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00076.H $         */
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

#ifndef __PROC_REG00076_H_
#define __PROC_REG00076_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIRMASK_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RW]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR]


//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_RDDATATO_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_SUE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_CE_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_UNEXPDATA_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_PARITY_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_WRADRERR_FW_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_BADCRESP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_RD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_OPERTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCUE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ACK_DEAD_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_PB_ADRERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_RDDATATO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_SUE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_UE_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_BCDE_CE_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_INTERNAL_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_ILLEGAL_CACHE_OP_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXSND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_PB_ACKDEAD_FW_WR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_DLO_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIRCV_RSVDATA_TO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXIFLOW_ERR_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DHI_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_DLO_RTYTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_AXISND_RSVTO_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39,
           TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39,
           TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIRMASK_RW, TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_AND,
                           TP_TPBR_PBA_PBAF_PBAFIRMASK_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39,
           TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIRMASK_RESERVED_37_39]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABAR3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR3;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABAR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABAR3]


//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR3_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR3_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR3_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR3_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR3_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR3_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR3_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR3_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR3_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR3_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR3_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR3_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR3_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR3_VTARGET]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABARMSK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABARMSK2]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK2;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK2]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABARMSK2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK2(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK2));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABARMSK2]


//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]

//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK2));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK2));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK2_PBABARMSK2_MSK]

//>> PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL3;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]

//>> PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL3]


//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL3));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL3_MASTERID]

//>> PREP_[TP_TPBR_PBA_PBAO_PBASLVRST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBASLVRST(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVRST;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBASLVRST]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVRST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBASLVRST(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVRST;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBASLVRST, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVRST]

//>> PUT_[TP_TPBR_PBA_PBAO_PBASLVRST]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBASLVRST(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBASLVRST, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBASLVRST]


//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_SET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_SET,
           TP_TPBR_PBA_PBAO_PBASLVRST_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_SET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_SET,
           TP_TPBR_PBA_PBAO_PBASLVRST_SET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVRST_SET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVRST_SET,
           TP_TPBR_PBA_PBAO_PBASLVRST_SET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVRST_SET]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG,
           TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG,
           TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG,
           TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS,
           TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS,
           TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS,
           TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR,
           TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR,
           TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVRST));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR,
           TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVRST_SCOPE_ATTN_BAR]

//>> PREP_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]

//>> PUT_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1]


//>> SET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> SET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1));
#endif
    return o_data.insertFromRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> GET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1));
#endif
    return i_data.extractToRight<TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP,
           TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_NET_PCBSLN0_MULTICAST_GROUP_1_MULTICAST1_GROUP]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_IR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIRAMEDR_EDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
