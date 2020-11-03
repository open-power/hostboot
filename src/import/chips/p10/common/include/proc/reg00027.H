/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00027.H $         */
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

#ifndef __PROC_REG00027_H_
#define __PROC_REG00027_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM67_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM67_PTL_FIR_REG_RW]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_RW]

//>> PUT_[PB_PTLSCOM67_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM67_PTL_FIR_REG_RW]

//>> PREP_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]

//>> PUT_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM67_PTL_FIR_REG_WO_AND]

//>> PREP_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM67_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM67_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM67_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]

//>> PUT_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM67_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM67_PTL_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM67_PTL_FIR_REG_WO_OR]


//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]
static inline bool GET_PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM67_PTL_FIR_REG_RW, PB_PTLSCOM67_PTL_FIR_REG_WO_AND, PB_PTLSCOM67_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM67_PTL_FIR_REG_PTL3_SPARE]

//>> PREP_[TP_TCN1_N1_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CTRL0_RW]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_RW;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RW]

//>> PUT_[TP_TCN1_N1_CPLT_CTRL0_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CTRL0_RW]

//>> PREP_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]

//>> PUT_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR]

//>> PREP_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_CPLT_CTRL0_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]

//>> PUT_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_CPLT_CTRL0_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_CPLT_CTRL0_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_CPLT_CTRL0_WO_OR]


//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_VITL_PROTECTION]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_11A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_18A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_19A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_TC_PSRO_SEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_32A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_33A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_34A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_35A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_38A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_39A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC,
           TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_42A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_43A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_48A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_49A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_50A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_51A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_52A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_53A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_54A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_RESERVED_55A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_56A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_57A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_58A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_59A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_60A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_61A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_62A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.setBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return o_data.clearBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.extractToRight<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]
static inline bool GET_TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_CPLT_CTRL0_RW, TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, TP_TCN1_N1_CPLT_CTRL0_WO_OR));
#endif
    return i_data.getBit<TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_CPLT_CTRL0_FREE_USAGE_63A]

//>> PREP_[TP_TPBR_PBA_PBAO_BCDE_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCDE_CTL]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCDE_CTL;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_CTL]

//>> PUT_[TP_TPBR_PBA_PBAO_BCDE_CTL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCDE_CTL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCDE_CTL]


//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_OP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_OP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_OP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_OP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_OP]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> CLEAR_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCDE_CTL_ART,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]
static inline bool GET_TP_TPBR_PBA_PBAO_BCDE_CTL_ART(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCDE_CTL));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_BCDE_CTL_ART>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCDE_CTL_ART chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCDE_CTL_ART]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABAR0]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABAR0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABAR0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABAR0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABAR0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABAR0]


//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE,
           TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0_CMD_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_ADDR,
           TP_TPBR_PBA_PBAO_PBABAR0_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_ADDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]

//>> SET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]

//>> GET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABAR0_VTARGET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABAR0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABAR0_VTARGET,
           TP_TPBR_PBA_PBAO_PBABAR0_VTARGET_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABAR0_VTARGET chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABAR0_VTARGET]

//>> PREP_[TP_TPBR_PBA_PBAO_PBABARMSK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBABARMSK1]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBABARMSK1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBABARMSK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBABARMSK1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBABARMSK1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBABARMSK1]


//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]

//>> SET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]

//>> GET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBABARMSK1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK,
           TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBABARMSK1_PBABARMSK1_MSK]

//>> PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBARBUFVAL0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBARBUFVAL0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBARBUFVAL0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBARBUFVAL0]


//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_RD_SLVNUM]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_CUR_RD_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_PREFETCH]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_ABORT]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_BUFFER_STATUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]

//>> SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]

//>> GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBARBUFVAL0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID,
           TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBARBUFVAL0_MASTERID]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAXSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAXSHBR1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHBR1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHBR1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAXSHBR1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHBR1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHBR1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAXSHBR1]


//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHBR1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START,
           TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHBR1_PUSH_START]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAXSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAXSHCS0]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAXSHCS0;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAXSHCS0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAXSHCS0(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXSHCS0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAXSHCS0]


//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_FULL]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_EMPTY]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_RESERVED_2_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_INTR_ACTION_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_LENGTH]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_WRITE_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR,
           TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_READ_PTR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAXSHCS0));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAXSHCS0_PUSH_ENABLE]

//>> PREP_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]

//>> PUT_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG]


//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]

//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR]

//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> CLEAR_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]
static inline bool GET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN]

//>> PREP_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]

//>> PUT_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG]


//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]

//>> SET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]

//>> GET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR,
           TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR]

//>> PREP_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG]


//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_INTADDR_REG_7]

//>> PREP_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CH_MISC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CH_MISC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG]


//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_FSM1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE,
           TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_TFRAMESIZE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN0]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN1]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_WEN2]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_EN_SCRD]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CH_MISC_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CH_MISC_REG_STTRTOGX]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
