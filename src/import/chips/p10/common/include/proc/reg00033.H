/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00033.H $         */
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

#ifndef __PROC_REG00033_H_
#define __PROC_REG00033_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_RW]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_AND]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFIR_WO_OR]


//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_DLO_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIRCV_RSVDATA_TO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DHI_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_DLO_RTYTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_AXISND_RSVTO]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_37]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_38]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFIR_RW, TP_TPBR_PBA_PBAF_PBAFIR_WO_AND, TP_TPBR_PBA_PBAF_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_39]

//>> PREP_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_OCIBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_OCIBAR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_OCIBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]

//>> PUT_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_OCIBAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_OCIBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR]


//>> SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_OCIBAR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR,
           TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR]

//>> PREP_[TP_TPBR_PBA_PBAO_BCDE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_STAT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_STAT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCDE_STAT]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_STAT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_STAT;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_STAT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT]

//>> PUT_[TP_TPBR_PBA_PBAO_BCDE_STAT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_STAT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_STAT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCDE_STAT]


//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP,
           TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG,
           TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_STAT_DONE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_STAT));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_STAT_DONE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_STAT_DONE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_STAT_DONE]

//>> PREP_[TP_TPBR_PBA_PBAO_PBASLVCTL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBASLVCTL0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVCTL0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBASLVCTL0]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBASLVCTL0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBASLVCTL0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBASLVCTL0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBASLVCTL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBASLVCTL0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBASLVCTL0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBASLVCTL0]


//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR,
           TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]
static inline bool GET_TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBASLVCTL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50]

//>> PREP_[TP_TPBR_PSIHB_TRUST_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_TRUST_CONTROL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_TRUST_CONTROL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_TRUST_CONTROL]

//>> GET_[TP_TPBR_PSIHB_TRUST_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_TRUST_CONTROL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_TRUST_CONTROL;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_TRUST_CONTROL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_TRUST_CONTROL]

//>> PUT_[TP_TPBR_PSIHB_TRUST_CONTROL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_TRUST_CONTROL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_TRUST_CONTROL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_TRUST_CONTROL]


//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> CLEAR_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> GET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> GET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]
static inline bool GET_TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE]

//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> CLEAR_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> GET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> GET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]
static inline bool GET_TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_TRUST_CONTROL));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_TRUST_CONTROL_SECURE_BOOTH]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR,
           TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_HCP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRAP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_IAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SIB]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_RDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WDAC]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_WS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_TRH]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_SMS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_LP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_EP]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_PTR]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_ST]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MFE]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_XSR_MCS]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG_SPRG0]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline fapi2::buffer<uint64_t>&
GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_SGB_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU_SGB_INFO_UPPER]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CLEAR_STICKY_BITS_2A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0,
           TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD0A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SRD0A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD0A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD0A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SRD0A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD0A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SRD0A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A,
           TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD2A;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_O2SWD2A;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD2A, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD2A));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_O2SWD2A, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD2A));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_O2SWD2A));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A,
           TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCBSES3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCBSES3;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCBSES3(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCBSES3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCBSES3));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OCCHBR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCHBR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OCCHBR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCHBR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OCCHBR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCHBR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT,
           TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]
static inline bool GET_TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OCCHBR));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0,
           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0,
           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0,
           TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0,
           TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0,
           TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW, TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR,
                           TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0,
           TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0]

//>> PREP_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_OCB_OINKR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OINKR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_OCB_OINKR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_OCB_OINKR0;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OINKR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]

//>> PUT_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_OCB_OINKR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OINKR0));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OINKR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_OCB_OINKR0]


//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OINKR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0,
           TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]

//>> SET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OINKR0));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0,
           TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]

//>> GET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_OCB_OINKR0));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0,
           TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
