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

//>> PREP_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG;
#endif
    return fapi2::getScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]

//>> PUT_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return fapi2::putScom(i_target, TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG]


//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCWR_TO_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RXSC]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_DISABLE_ECC_COR_RXRF_PSI]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CRC_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_ENABLE_SCRD_FR_RXRF]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_ENABLE_STREAMING_MODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_INTERFACEMODE]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.insertFromRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& SET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.setBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& CLEAR_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return o_data.clearBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline fapi2::buffer<uint64_t>& GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.extractToRight<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]
static inline bool GET_TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG));
#endif
    return i_data.getBit<TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TP_TPBR_PSI_WRAP_RX_CTRL_STAT_REG_RX_CHIP_PERSONALISATION]

//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK,
           PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
