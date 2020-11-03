/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/proc/reg00050.H $         */
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

#ifndef __PROC_REG00050_H_
#define __PROC_REG00050_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace proc
{
#endif


//>> PREP_[PB_BRIDGE_NHTM_SC_HTM_FILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_PB_BRIDGE_NHTM_SC_HTM_FILT(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_FILT;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[PB_BRIDGE_NHTM_SC_HTM_FILT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_PB_BRIDGE_NHTM_SC_HTM_FILT(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = PB_BRIDGE_NHTM_SC_HTM_FILT;
#endif
    return fapi2::getScom(i_target, PB_BRIDGE_NHTM_SC_HTM_FILT, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT]

//>> PUT_[PB_BRIDGE_NHTM_SC_HTM_FILT]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_PB_BRIDGE_NHTM_SC_HTM_FILT(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return fapi2::putScom(i_target, PB_BRIDGE_NHTM_SC_HTM_FILT, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[PB_BRIDGE_NHTM_SC_HTM_FILT]


//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO24_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_MCD_TTAG]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_0]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x20));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.setBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline fapi2::buffer<uint64_t>& CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.clearBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]
static inline bool GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.getBit<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK_1]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC24TO26_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]

//>> SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return o_data.insertFromRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]

//>> GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]
static inline fapi2::buffer<uint64_t>& GET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(PB_BRIDGE_NHTM_SC_HTM_FILT));
#endif
    return i_data.extractToRight<PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK,
           PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_proc Invalid dial access PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
