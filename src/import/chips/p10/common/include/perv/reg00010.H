/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/perv/reg00010.H $         */
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

#ifndef __PERV_REG00010_H_
#define __PERV_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> PREP_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_CLKSTOP_ON_XSTOP_MASK1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_CLKSTOP_ON_XSTOP_MASK1;
#endif
    return fapi2::getScom(i_target, EPS_FIR_CLKSTOP_ON_XSTOP_MASK1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]

//>> PUT_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return fapi2::putScom(i_target, EPS_FIR_CLKSTOP_ON_XSTOP_MASK1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1]


//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.insertFromRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.setBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return o_data.clearBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.extractToRight<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]
static inline bool GET_EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_CLKSTOP_ON_XSTOP_MASK1));
#endif
    return i_data.getBit<EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15]

//>> PREP_[EPS_THERM_WSUB2_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_THERM_WSUB2_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_DTS_RESULT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_THERM_WSUB2_DTS_RESULT1]

//>> GET_[EPS_THERM_WSUB2_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_THERM_WSUB2_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_THERM_WSUB2_DTS_RESULT1;
#endif
    return fapi2::getScom(i_target, EPS_THERM_WSUB2_DTS_RESULT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_RESULT1]

//>> PUT_[EPS_THERM_WSUB2_DTS_RESULT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_THERM_WSUB2_DTS_RESULT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return fapi2::putScom(i_target, EPS_THERM_WSUB2_DTS_RESULT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_THERM_WSUB2_DTS_RESULT1]


//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]

//>> GET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]

//>> GET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]

//>> SET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& SET_EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return o_data.insertFromRight<EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]

//>> GET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]
static inline fapi2::buffer<uint64_t>& GET_EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_THERM_WSUB2_DTS_RESULT1));
#endif
    return i_data.extractToRight<EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT,
           EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT]

//>> PREP_[ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_STATUS]

//>> GET_[ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_STATUS;
#endif
    return fapi2::getScom(i_target, ERROR_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_STATUS]

//>> PUT_[ERROR_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return fapi2::putScom(i_target, ERROR_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_STATUS]


//>> SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> GET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> GET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]
static inline bool GET_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> GET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> GET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]
static inline bool GET_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]
static inline bool GET_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_PARITY_ON_CMD_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_CMD_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_CMD_ERR]

//>> SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> GET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> GET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]
static inline bool GET_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]
static inline bool GET_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]
static inline bool GET_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_PARITY_ON_DATA_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_DATA_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_DATA_ERR]

//>> SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> GET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> GET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]
static inline bool GET_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> GET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]
static inline bool GET_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR]

//>> SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> CLEAR_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> GET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> GET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]
static inline bool GET_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> CLEAR_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> GET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> GET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]
static inline bool GET_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> CLEAR_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> GET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> GET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]
static inline bool GET_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR]

//>> SET_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_COLLISION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> CLEAR_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> GET_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_SCAN_COLLISION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> GET_[ERROR_STATUS_SCAN_COLLISION_ERR]
static inline bool GET_ERROR_STATUS_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> CLEAR_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> GET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> GET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]
static inline bool GET_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR]

//>> SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_TRIGGER_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> CLEAR_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> GET_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_OPCG_TRIGGER_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> GET_[ERROR_STATUS_OPCG_TRIGGER_ERR]
static inline bool GET_ERROR_STATUS_OPCG_TRIGGER_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_OPCG_TRIGGER_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_OPCG_TRIGGER_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_OPCG_TRIGGER_ERR]

//>> SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> CLEAR_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> GET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> GET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]
static inline bool GET_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> CLEAR_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> GET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> GET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]
static inline bool GET_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_OPCG_SM_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_SM_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_OPCG_SM_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_OPCG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_OPCG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_OPCG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_GPIO_REG_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_GPIO_REG_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_GPIO_REG_ERR]

//>> SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLKCMD_REQUEST_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> CLEAR_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> GET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_CLKCMD_REQUEST_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> GET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]
static inline bool GET_ERROR_STATUS_CLKCMD_REQUEST_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_CLKCMD_REQUEST_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_CLKCMD_REQUEST_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CLKCMD_REQUEST_ERR]

//>> SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CBS_PROTOCOL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> CLEAR_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> GET_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_CBS_PROTOCOL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> GET_[ERROR_STATUS_CBS_PROTOCOL_ERR]
static inline bool GET_ERROR_STATUS_CBS_PROTOCOL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_CBS_PROTOCOL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_CBS_PROTOCOL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_CBS_PROTOCOL_ERR]

//>> SET_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_VITL_ALIGN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> SET_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_VITL_ALIGN_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_VITL_ALIGN_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> SET_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> CLEAR_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> GET_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_VITL_ALIGN_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> GET_[ERROR_STATUS_VITL_ALIGN_ERR]
static inline bool GET_ERROR_STATUS_VITL_ALIGN_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_VITL_ALIGN_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_VITL_ALIGN_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_VITL_ALIGN_ERR]

//>> SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_UNIT_SYNC_LVL_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> CLEAR_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> GET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_UNIT_SYNC_LVL_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> GET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]
static inline bool GET_ERROR_STATUS_UNIT_SYNC_LVL_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_UNIT_SYNC_LVL_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_UNIT_SYNC_LVL_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_UNIT_SYNC_LVL_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> CLEAR_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> GET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]
static inline bool GET_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR]

//>> SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.insertFromRight<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.setBit<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> CLEAR_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return o_data.clearBit<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> GET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.extractToRight<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> GET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]
static inline bool GET_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_STATUS));
#endif
    return i_data.getBit<ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE]

//>> PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW;
#endif
    return fapi2::getScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]

//>> PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return fapi2::putScom(i_target, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW]


//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]

//>> SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]
static inline fapi2::buffer<uint64_t>& SET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return o_data.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]

//>> GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]
static inline fapi2::buffer<uint64_t>& GET_FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI, FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_FSI_BYTE,
                           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW));
#endif
    return i_data.extractToRight<FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG,
           FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_ROOT_CTRL7_COPY_REG]

//>> PREP_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW]

//>> GET_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW]

//>> PUT_[NET_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW]

//>> PREP_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WAND;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW_WAND]

//>> GET_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WAND;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW_WAND, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW_WAND]

//>> PUT_[NET_CTRL1_RW_WAND]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW_WAND(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW_WAND, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW_WAND]

//>> PREP_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WOR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[NET_CTRL1_RW_WOR]

//>> GET_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = NET_CTRL1_RW_WOR;
#endif
    return fapi2::getScom(i_target, NET_CTRL1_RW_WOR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[NET_CTRL1_RW_WOR]

//>> PUT_[NET_CTRL1_RW_WOR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_NET_CTRL1_RW_WOR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return fapi2::putScom(i_target, NET_CTRL1_RW_WOR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[NET_CTRL1_RW_WOR]


//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CACHE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE0_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE1_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE2_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_DCC_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]
static inline bool GET_NET_CTRL1_CORE3_CLK_DCC_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_DCC_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCC_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCC_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CACHE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE0_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE1_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE2_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_PDLY_BYPASS,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]
static inline bool GET_NET_CTRL1_CORE3_CLK_PDLY_BYPASS(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_PDLY_BYPASS>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_PDLY_BYPASS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_PDLY_BYPASS]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.setBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> CLEAR_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.clearBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]
static inline bool GET_NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.getBit<NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC]

//>> SET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PCB_ACCESS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_PCB_ACCESS]

//>> SET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& SET_NET_CTRL1_PCB_ACCESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return o_data.insertFromRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[NET_CTRL1_PCB_ACCESS]

//>> GET_[NET_CTRL1_PCB_ACCESS]
static inline fapi2::buffer<uint64_t>& GET_NET_CTRL1_PCB_ACCESS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(NET_CTRL1_RW, NET_CTRL1_RW_WAND, NET_CTRL1_RW_WOR));
#endif
    return i_data.extractToRight<NET_CTRL1_PCB_ACCESS,
           NET_CTRL1_PCB_ACCESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access NET_CTRL1_PCB_ACCESS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[NET_CTRL1_PCB_ACCESS]

//>> PREP_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_LONG_ROTATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN_LONG_ROTATE]

//>> GET_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_LONG_ROTATE;
#endif
    return fapi2::getScom(i_target, SCAN_LONG_ROTATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN_LONG_ROTATE]

//>> PUT_[SCAN_LONG_ROTATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN_LONG_ROTATE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN_LONG_ROTATE));
#endif
    return fapi2::putScom(i_target, SCAN_LONG_ROTATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN_LONG_ROTATE]


//>> PREP_[TOD_START_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_TOD_START_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_START_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[TOD_START_REG]

//>> GET_[TOD_START_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_TOD_START_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = TOD_START_REG;
#endif
    return fapi2::getScom(i_target, TOD_START_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[TOD_START_REG]

//>> PUT_[TOD_START_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_TOD_START_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return fapi2::putScom(i_target, TOD_START_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[TOD_START_REG]


//>> SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_FSM_START_TOD_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_TRIGGER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_FSM_START_TOD_TRIGGER,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.setBit<TOD_START_REG_FSM_START_TOD_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> CLEAR_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_START_REG_FSM_START_TOD_TRIGGER(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.clearBit<TOD_START_REG_FSM_START_TOD_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> GET_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline fapi2::buffer<uint64_t>& GET_TOD_START_REG_FSM_START_TOD_TRIGGER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.extractToRight<TOD_START_REG_FSM_START_TOD_TRIGGER,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> GET_[TOD_START_REG_FSM_START_TOD_TRIGGER]
static inline bool GET_TOD_START_REG_FSM_START_TOD_TRIGGER(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.getBit<TOD_START_REG_FSM_START_TOD_TRIGGER>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_TRIGGER chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_FSM_START_TOD_TRIGGER]

//>> SET_[TOD_START_REG_REG_0X22_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_REG_0X22_SPARE_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_REG_0X22_SPARE_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_REG_0X22_SPARE_01]

//>> SET_[TOD_START_REG_REG_0X22_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_REG_0X22_SPARE_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_REG_0X22_SPARE_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_REG_0X22_SPARE_01]

//>> SET_[TOD_START_REG_REG_0X22_SPARE_01]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_REG_0X22_SPARE_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.setBit<TOD_START_REG_REG_0X22_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_REG_0X22_SPARE_01]

//>> CLEAR_[TOD_START_REG_REG_0X22_SPARE_01]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_START_REG_REG_0X22_SPARE_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.clearBit<TOD_START_REG_REG_0X22_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_START_REG_REG_0X22_SPARE_01]

//>> GET_[TOD_START_REG_REG_0X22_SPARE_01]
static inline fapi2::buffer<uint64_t>& GET_TOD_START_REG_REG_0X22_SPARE_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.extractToRight<TOD_START_REG_REG_0X22_SPARE_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_REG_0X22_SPARE_01]

//>> GET_[TOD_START_REG_REG_0X22_SPARE_01]
static inline bool GET_TOD_START_REG_REG_0X22_SPARE_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.getBit<TOD_START_REG_REG_0X22_SPARE_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_REG_0X22_SPARE_01]

//>> SET_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_DATA02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_FSM_START_TOD_DATA02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> SET_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_DATA02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_FSM_START_TOD_DATA02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> SET_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_FSM_START_TOD_DATA02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.setBit<TOD_START_REG_FSM_START_TOD_DATA02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> CLEAR_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline fapi2::buffer<uint64_t>& CLEAR_TOD_START_REG_FSM_START_TOD_DATA02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.clearBit<TOD_START_REG_FSM_START_TOD_DATA02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> GET_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline fapi2::buffer<uint64_t>& GET_TOD_START_REG_FSM_START_TOD_DATA02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.extractToRight<TOD_START_REG_FSM_START_TOD_DATA02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> GET_[TOD_START_REG_FSM_START_TOD_DATA02]
static inline bool GET_TOD_START_REG_FSM_START_TOD_DATA02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.getBit<TOD_START_REG_FSM_START_TOD_DATA02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_perv Invalid dial access TOD_START_REG_FSM_START_TOD_DATA02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_FSM_START_TOD_DATA02]

//>> SET_[TOD_START_REG_REG_0X22_SPARE_03_07]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_REG_0X22_SPARE_03_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_REG_0X22_SPARE_03_07,
           TOD_START_REG_REG_0X22_SPARE_03_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_03_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_REG_0X22_SPARE_03_07]

//>> SET_[TOD_START_REG_REG_0X22_SPARE_03_07]
static inline fapi2::buffer<uint64_t>& SET_TOD_START_REG_REG_0X22_SPARE_03_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return o_data.insertFromRight<TOD_START_REG_REG_0X22_SPARE_03_07,
           TOD_START_REG_REG_0X22_SPARE_03_07_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_03_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[TOD_START_REG_REG_0X22_SPARE_03_07]

//>> GET_[TOD_START_REG_REG_0X22_SPARE_03_07]
static inline fapi2::buffer<uint64_t>& GET_TOD_START_REG_REG_0X22_SPARE_03_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(TOD_START_REG));
#endif
    return i_data.extractToRight<TOD_START_REG_REG_0X22_SPARE_03_07,
           TOD_START_REG_REG_0X22_SPARE_03_07_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_perv Invalid dial access TOD_START_REG_REG_0X22_SPARE_03_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[TOD_START_REG_REG_0X22_SPARE_03_07]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
