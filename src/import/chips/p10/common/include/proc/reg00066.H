/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00066.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __PROC_REG00066_H_
#define __PROC_REG00066_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM23_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM23_PTL_FIR_REG_RW]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_RW]

//>> PUT_[PB_PTLSCOM23_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM23_PTL_FIR_REG_RW]

//>> PREP_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]

//>> PUT_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM23_PTL_FIR_REG_WO_AND]

//>> PREP_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM23_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM23_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM23_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]

//>> PUT_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM23_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM23_PTL_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM23_PTL_FIR_REG_WO_OR]


//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]
static inline bool GET_PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM23_PTL_FIR_REG_RW, PB_PTLSCOM23_PTL_FIR_REG_WO_AND, PB_PTLSCOM23_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM23_PTL_FIR_REG_PTL3_SPARE]

//>> PREP_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]

//>> PUT_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG]


//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2,
           TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]
static inline bool GET_TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3]

//>> PREP_[TP_TPBR_PBA_PBAF_PBAFCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAF_PBAFCFG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFCFG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAF_PBAFCFG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAF_PBAFCFG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAF_PBAFCFG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAF_PBAFCFG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG]

//>> PUT_[TP_TPBR_PBA_PBAF_PBAFCFG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAF_PBAFCFG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAF_PBAFCFG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAF_PBAFCFG]


//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_ON_HANG_PBAX]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DATA_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_DROP_PRIORITY_MASK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_OPER_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_DATA_HANG]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_ECC_CHECK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RETRY_BACKOFF]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_EXIT_ON_INVALID_CRESP]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_RTAG_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_DIS_PB_PARITY_CHK]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_SKIP_GROUP_SCOPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_PR_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_CHSW_USE_CL_DMA_INJ]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX,
           TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EVENT_MUX]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DIS_CHGRATE_COUNT]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_HTM_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_TRACE_ENABLE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_DEBUG_TRACE_SEL]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]
static inline bool GET_TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_RESERVED_43]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_TYPE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]

//>> SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]

//>> GET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAF_PBAFCFG));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE,
           TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAF_PBAFCFG_INJECT_MODE]

//>> PREP_[TP_TPBR_PBA_PBAO_BCUE_SET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_BCUE_SET(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_SET;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_BCUE_SET]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_SET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_BCUE_SET(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_BCUE_SET;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_SET, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_SET]

//>> PUT_[TP_TPBR_PBA_PBAO_BCUE_SET]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_BCUE_SET(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_SET, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_BCUE_SET]


//>> SET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1,
           TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_SET_RESERVED_0_1]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]

//>> SET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]

//>> GET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_BCUE_SET));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH,
           TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_BCUE_SET_COPY_LENGTH]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIR_RW]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_RW;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RW]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIR_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIR_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIR_RW]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_WO_AND;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIR_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIR_WO_AND]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIR_WO_OR;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIR_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIR_WO_OR]


//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_APAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_SLAVE_INIT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_WRPAR_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCUE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_SETUP_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_BCDE_OCI_DATERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_INTERNAL_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_OCI_BAD_REG_ADDR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIPUSH_WRERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXIFLOW_ERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXSND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_AXISND_RSVERR]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_HTM_WRITE_OVERFLOW]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_INVALID_TOPOLOGY_ID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_18]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIR_RW, TP_TPBR_PBA_PBAO_PBAFIR_WO_AND, TP_TPBR_PBA_PBAO_PBAFIR_WO_OR));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIR_RESERVED_19]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRACT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAFIRACT1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAFIRACT1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRACT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRACT1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAFIRACT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAFIRACT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRACT1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAFIRACT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAFIRACT1]


//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRACT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAFIRACT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1,
           TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAFIRACT1_PBAFIRACT1_FIR_ACTION1]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAMODE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAMODE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAMODE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAMODE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAMODE;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAMODE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAMODE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAMODE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAMODE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAMODE]


//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_0_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REARB]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MSTID_MATCH_PREF_INV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_RDPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_SLAVE_WRPIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_9]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_REREQUEST_TO]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_12_13]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_14_15]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION,
           TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION,
           TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION,
           TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE,
           TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE,
           TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE,
           TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS,
           TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_RD_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DIS_MASTER_WR_PIPE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_EN_EVENT_COUNT]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_29]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX,
           TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX,
           TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX,
           TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_SLV_EVENT_MUX]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_ENABLE_DEBUG_BUS]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_PB_NOT_OCI]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE,
           TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE,
           TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE,
           TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_DEBUG_OCI_MODE]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.setBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]
static inline bool GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.getBit<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_39]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_FAIRNESS_MASK]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV,
           TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_OCISLV_REREQ_HANG_DIV]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]

//>> SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]

//>> GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAMODE));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63,
           TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAMODE_RESERVED_50_63]

//>> PREP_[TP_TPBR_PBA_PBAO_PBAPBTXT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PBA_PBAO_PBAPBTXT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAPBTXT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PBA_PBAO_PBAPBTXT1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PBA_PBAO_PBAPBTXT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PBA_PBAO_PBAPBTXT1;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAPBTXT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1]

//>> PUT_[TP_TPBR_PBA_PBAO_PBAPBTXT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PBA_PBAO_PBAPBTXT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAPBTXT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PBA_PBAO_PBAPBTXT1]


//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_VALID]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_0,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_0]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_1,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_1]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_2,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_2]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_3,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_3]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_4,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_4]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_5,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_5]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_6,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_6]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]

//>> SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PBA_PBAO_PBAPBTXT1_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return o_data.insertFromRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]

//>> GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PBA_PBAO_PBAPBTXT1_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PBA_PBAO_PBAPBTXT1));
#endif
    return i_data.extractToRight<TP_TPBR_PBA_PBAO_PBAPBTXT1_7,
           TP_TPBR_PBA_PBAO_PBAPBTXT1_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PBA_PBAO_PBAPBTXT1_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PBA_PBAO_PBAPBTXT1_7]

//>> PREP_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG]


//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_0]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_1]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_2]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_3]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_4]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_5]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_6]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]
static inline bool GET_TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_TX_CH_INTADDR_REG_7]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART1]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXISIB_PIB_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.setBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.clearBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]
static inline bool GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING(
    fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.getBit<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_OCB_OCI_GPEXIMEM_MEM_IFETCH_PENDING]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACL_ICACHE_INFO_LOWER_PART2]

//>> PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU;
#endif
    return fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]

//>> PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU));
#endif
    return fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU]


//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& SET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU));
#endif
    return o_data.insertFromRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]
static inline fapi2::buffer<uint64_t>& GET_TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU));
#endif
    return i_data.extractToRight<TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER,
           TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIICACU_ICACHE_INFO_UPPER]

//>> PREP_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_DF_FSM_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]

//>> GET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_DF_FSM_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_DF_FSM_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_DF_FSM_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_DF_FSM_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG]


//>> SET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_DF_FSM_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM,
           TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]

//>> SET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_DF_FSM_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM,
           TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]

//>> GET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_DF_FSM_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM,
           TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_DF_FSM_REG_RX_DF_FSM]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
