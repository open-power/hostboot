/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00006.H $         */
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

#ifndef __PROC_REG00006_H_
#define __PROC_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_RW;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_RW]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR00_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR01_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR02_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FMR03_TRAINED]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_UE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_CE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_SUE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DOB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_CROB23_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_FRAMER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER00_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER01_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER02_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PARSER03_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_0_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_1_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_2_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_LINK_DOWN_3_ATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB01_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_DIB23_ERR]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB00_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB01_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB10_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB11_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB20_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB21_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB30_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_MB31_SPATTN]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL0_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL1_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL2_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]
static inline bool GET_PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_PTL3_SPARE]

//>> PREP_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_ALTD_DATA_REG]

//>> GET_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_ALTD_DATA_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_ALTD_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_DATA_REG]

//>> PUT_[TP_TPBR_AD_ALTD_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_ALTD_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_ALTD_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_ALTD_DATA_REG]


//>> SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]

//>> SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]

//>> GET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_ALTD_DATA_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA,
           TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_ALTD_DATA_REG_FBC_ALTD_DATA]

//>> PREP_[TP_TPBR_AD_FORCE_ECC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_AD_FORCE_ECC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_FORCE_ECC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_AD_FORCE_ECC_REG]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_AD_FORCE_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_AD_FORCE_ECC_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_AD_FORCE_ECC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG]

//>> PUT_[TP_TPBR_AD_FORCE_ECC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_AD_FORCE_ECC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_AD_FORCE_ECC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_AD_FORCE_ECC_REG]


//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_ITAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_ITAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_FORCE_ECC_REG_ITAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> CLEAR_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_FORCE_ECC_REG_ITAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_FORCE_ECC_REG_ITAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_FORCE_ECC_REG_ITAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]
static inline bool GET_TP_TPBR_AD_FORCE_ECC_REG_ITAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_FORCE_ECC_REG_ITAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_ITAG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG_ITAG]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC,
           TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC,
           TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC,
           TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.setBit<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> CLEAR_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return o_data.clearBit<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return i_data.extractToRight<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]
static inline bool GET_TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_AD_FORCE_ECC_REG));
#endif
    return i_data.getBit<TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_AD_FORCE_ECC_REG_TX_ECC_OVERWRITE]

//>> PREP_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PR0123_ERR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PR0123_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PR0123_ERR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PR0123_ERR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR]

//>> PUT_[PB_PTLSCOM45_PR0123_ERR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PR0123_ERR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PR0123_ERR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PR0123_ERR]


//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_0_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_1_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_2_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ADDRESS_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_ATAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC2_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CC3_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_CONTROL_ERROR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_DATA_PTY_ERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_MISC_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_RTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_TTAG_PTY]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC0_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_VC1_CREDITERR]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.insertFromRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& SET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.setBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return o_data.clearBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline fapi2::buffer<uint64_t>& GET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.extractToRight<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]
static inline bool GET_PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PR0123_ERR));
#endif
    return i_data.getBit<PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_PTLSCOM45_PR0123_ERR_3_LINK_DOWN]

//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_AND;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_WO_AND(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_AND]

//>> PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]

//>> GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_PTLSCOM45_PTL_FIR_REG_WO_OR;
#endif
    return fapi2::getScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]

//>> PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_PTLSCOM45_PTL_FIR_REG_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_PTLSCOM45_PTL_FIR_REG_RW, PB_PTLSCOM45_PTL_FIR_REG_WO_AND, PB_PTLSCOM45_PTL_FIR_REG_WO_OR));
#endif
    return fapi2::putScom(i_target, PB_PTLSCOM45_PTL_FIR_REG_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_PTLSCOM45_PTL_FIR_REG_WO_OR]


//>> PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1;
#endif
    return fapi2::getScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]

//>> PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return fapi2::putScom(i_target, TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1]


//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_00]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_01]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_02]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_03]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_04]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_05]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_06]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_07]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_08]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_09]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_10]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_11]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_12]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_13]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_14]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_15]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_16]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_17]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_18]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_19]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_20]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_21]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_22]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_23]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_24]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_25]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_26]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_27]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_28]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_29]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_30]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_31]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_32]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_33]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_34]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_35]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_36]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_37]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_38]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_39]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_40]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_41]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_42]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_43]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_44]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_45]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_46]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_47]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_48]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_49]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_50]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_51]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_52]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_53]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_54]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_55]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_56]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_57]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_58]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_59]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_60]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_61]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_62]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.insertFromRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>> SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& SET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.setBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>> CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return o_data.clearBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline fapi2::buffer<uint64_t>& GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.extractToRight<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>> GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]
static inline bool GET_TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1));
#endif
    return i_data.getBit<TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TCN1_N1_EPS_FIR_LOCAL_ACTION1_63]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
