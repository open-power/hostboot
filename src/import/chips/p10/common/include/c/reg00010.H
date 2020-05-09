/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/c/reg00010.H $            */
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

#ifndef __C_REG00010_H_
#define __C_REG00010_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> PREP_[CPMS_DPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPMS_DPMR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPMR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPMS_DPMR]

//>> GET_[CPMS_DPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPMS_DPMR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPMS_DPMR;
#endif
    return fapi2::getScom(i_target, CPMS_DPMR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPMS_DPMR]

//>> PUT_[CPMS_DPMR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPMS_DPMR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return fapi2::putScom(i_target, CPMS_DPMR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPMS_DPMR]


//>> SET_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_POWER_PROXY_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_POWER_PROXY_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> SET_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_POWER_PROXY_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_POWER_PROXY_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> SET_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_POWER_PROXY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_POWER_PROXY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> CLEAR_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_POWER_PROXY_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_POWER_PROXY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> GET_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_POWER_PROXY_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_POWER_PROXY_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> GET_[CPMS_DPMR_POWER_PROXY_ENABLE]
static inline bool GET_CPMS_DPMR_POWER_PROXY_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_POWER_PROXY_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_POWER_PROXY_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_POWER_PROXY_ENABLE]

//>> SET_[CPMS_DPMR_PROXY_CAL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PROXY_CAL_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_PROXY_CAL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PROXY_CAL_MODE]

//>> SET_[CPMS_DPMR_PROXY_CAL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PROXY_CAL_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_PROXY_CAL_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PROXY_CAL_MODE]

//>> SET_[CPMS_DPMR_PROXY_CAL_MODE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PROXY_CAL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_PROXY_CAL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PROXY_CAL_MODE]

//>> CLEAR_[CPMS_DPMR_PROXY_CAL_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_PROXY_CAL_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_PROXY_CAL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_PROXY_CAL_MODE]

//>> GET_[CPMS_DPMR_PROXY_CAL_MODE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_PROXY_CAL_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_PROXY_CAL_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_PROXY_CAL_MODE]

//>> GET_[CPMS_DPMR_PROXY_CAL_MODE]
static inline bool GET_CPMS_DPMR_PROXY_CAL_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_PROXY_CAL_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_PROXY_CAL_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_PROXY_CAL_MODE]

//>> SET_[CPMS_DPMR_PIL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PIL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_PIL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PIL_ENABLE]

//>> SET_[CPMS_DPMR_PIL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PIL_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_PIL_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PIL_ENABLE]

//>> SET_[CPMS_DPMR_PIL_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_PIL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_PIL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_PIL_ENABLE]

//>> CLEAR_[CPMS_DPMR_PIL_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_PIL_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_PIL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_PIL_ENABLE]

//>> GET_[CPMS_DPMR_PIL_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_PIL_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_PIL_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_PIL_ENABLE]

//>> GET_[CPMS_DPMR_PIL_ENABLE]
static inline bool GET_CPMS_DPMR_PIL_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_PIL_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_PIL_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_PIL_ENABLE]

//>> SET_[CPMS_DPMR_DDP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_DDP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_ENABLE]

//>> SET_[CPMS_DPMR_DDP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_DDP_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_ENABLE]

//>> SET_[CPMS_DPMR_DDP_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_DDP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_ENABLE]

//>> CLEAR_[CPMS_DPMR_DDP_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_DDP_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_DDP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_DDP_ENABLE]

//>> GET_[CPMS_DPMR_DDP_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_DDP_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_DDP_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_DDP_ENABLE]

//>> GET_[CPMS_DPMR_DDP_ENABLE]
static inline bool GET_CPMS_DPMR_DDP_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_DDP_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_DDP_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_DDP_ENABLE]

//>> SET_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_EMPATH_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_EMPATH_MODE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> SET_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_EMPATH_MODE_SEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_EMPATH_MODE_SEL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> SET_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_EMPATH_MODE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_EMPATH_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> CLEAR_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_EMPATH_MODE_SEL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_EMPATH_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> GET_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_EMPATH_MODE_SEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_EMPATH_MODE_SEL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> GET_[CPMS_DPMR_EMPATH_MODE_SEL]
static inline bool GET_CPMS_DPMR_EMPATH_MODE_SEL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_EMPATH_MODE_SEL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_EMPATH_MODE_SEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_EMPATH_MODE_SEL]

//>> SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_DDS_ADJUST_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_DDP_DDS_ADJUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_DDS_ADJUST_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_DDP_DDS_ADJUST_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_DDP_DDS_ADJUST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.setBit<CPMS_DPMR_DDP_DDS_ADJUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> CLEAR_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_CPMS_DPMR_DDP_DDS_ADJUST_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.clearBit<CPMS_DPMR_DDP_DDS_ADJUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> GET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_DDP_DDS_ADJUST_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_DDP_DDS_ADJUST_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> GET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]
static inline bool GET_CPMS_DPMR_DDP_DDS_ADJUST_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.getBit<CPMS_DPMR_DDP_DDS_ADJUST_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access CPMS_DPMR_DDP_DDS_ADJUST_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_DDP_DDS_ADJUST_EN]

//>> SET_[CPMS_DPMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_SPARE,
           CPMS_DPMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access CPMS_DPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_SPARE]

//>> SET_[CPMS_DPMR_SPARE]
static inline fapi2::buffer<uint64_t>& SET_CPMS_DPMR_SPARE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return o_data.insertFromRight<CPMS_DPMR_SPARE,
           CPMS_DPMR_SPARE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access CPMS_DPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPMS_DPMR_SPARE]

//>> GET_[CPMS_DPMR_SPARE]
static inline fapi2::buffer<uint64_t>& GET_CPMS_DPMR_SPARE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPMS_DPMR));
#endif
    return i_data.extractToRight<CPMS_DPMR_SPARE,
           CPMS_DPMR_SPARE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access CPMS_DPMR_SPARE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPMS_DPMR_SPARE]

//>> PREP_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1;
#endif
    return fapi2::getScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]

//>> PUT_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return fapi2::putScom(i_target, EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]


//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.insertFromRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline fapi2::buffer<uint64_t>& SET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.setBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return o_data.clearBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline fapi2::buffer<uint64_t>& GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.extractToRight<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]
static inline bool GET_EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1));
#endif
    return i_data.getBit<EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31]

//>> PREP_[EC_PC_FIR_CORE_SYS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_SYS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_SYS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_CORE_SYS]

//>> GET_[EC_PC_FIR_CORE_SYS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_SYS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_SYS;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_SYS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SYS]

//>> PUT_[EC_PC_FIR_CORE_SYS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_SYS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_SYS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_CORE_SYS]


//>> SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> CLEAR_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> GET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> GET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]
static inline bool GET_EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_SYS));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE]

//>> PREP_[EC_PC_FIR_CORE_WOF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_CORE_WOF(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WOF;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_CORE_WOF]

//>> GET_[EC_PC_FIR_CORE_WOF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_CORE_WOF(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_CORE_WOF;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_CORE_WOF, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF]

//>> PUT_[EC_PC_FIR_CORE_WOF]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_CORE_WOF(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_CORE_WOF, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_CORE_WOF]


//>> SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_6]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_6]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_STF_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_VS_STF_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_VS_STF_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_VS_STF_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_STF_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_STF_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_10]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_10]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_20]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_20]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_27]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_27]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_39]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_39]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_40]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_40]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_42]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_42]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_44]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_44]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_48]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_48]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_49]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_49]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_50]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_50]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_51]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_51]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_UNUSED_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_UNUSED_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_UNUSED_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_UNUSED_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> GET_[EC_PC_FIR_CORE_WOF_UNUSED_54]
static inline bool GET_EC_PC_FIR_CORE_WOF_UNUSED_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_UNUSED_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_UNUSED_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_UNUSED_54]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    const uint64_t i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.insertFromRight<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.setBit<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> CLEAR_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return o_data.clearBit<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.extractToRight<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> GET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]
static inline bool GET_EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_CORE_WOF));
#endif
    return i_data.getBit<EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR]

//>> PREP_[EC_PC_FIR_RAM_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_FIR_RAM_STATUS(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_STATUS;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_FIR_RAM_STATUS]

//>> GET_[EC_PC_FIR_RAM_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_FIR_RAM_STATUS(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_FIR_RAM_STATUS;
#endif
    return fapi2::getScom(i_target, EC_PC_FIR_RAM_STATUS, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS]

//>> PUT_[EC_PC_FIR_RAM_STATUS]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_FIR_RAM_STATUS(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return fapi2::putScom(i_target, EC_PC_FIR_RAM_STATUS, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_FIR_RAM_STATUS]


//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]
static inline bool GET_EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]
static inline bool GET_EC_PC_FIR_RAM_STATUS_RAM_COMPLETION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_STATUS_RAM_COMPLETION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_COMPLETION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_COMPLETION]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> GET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]
static inline bool GET_EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION]

//>> SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_LSU_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.insertFromRight<EC_PC_FIR_RAM_STATUS_LSU_EMPTY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.setBit<EC_PC_FIR_RAM_STATUS_LSU_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> CLEAR_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return o_data.clearBit<EC_PC_FIR_RAM_STATUS_LSU_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> GET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.extractToRight<EC_PC_FIR_RAM_STATUS_LSU_EMPTY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> GET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]
static inline bool GET_EC_PC_FIR_RAM_STATUS_LSU_EMPTY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_FIR_RAM_STATUS));
#endif
    return i_data.getBit<EC_PC_FIR_RAM_STATUS_LSU_EMPTY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_FIR_RAM_STATUS_LSU_EMPTY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_FIR_RAM_STATUS_LSU_EMPTY]

//>> PREP_[EC_PC_PMC_UPDATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_PMC_UPDATE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_UPDATE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_PMC_UPDATE]

//>> GET_[EC_PC_PMC_UPDATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_PMC_UPDATE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_PMC_UPDATE;
#endif
    return fapi2::getScom(i_target, EC_PC_PMC_UPDATE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE]

//>> PUT_[EC_PC_PMC_UPDATE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_PMC_UPDATE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return fapi2::putScom(i_target, EC_PC_PMC_UPDATE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_PMC_UPDATE]


//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]
static inline bool GET_EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]
static inline bool GET_EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> GET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]
static inline bool GET_EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]
static inline bool GET_EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT0_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT0_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT0_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT0_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT0_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT0_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT0_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT0_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT0_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT0_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]
static inline bool GET_EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT1_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT1_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT1_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT1_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT1_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT1_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT1_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT1_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT1_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT1_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]
static inline bool GET_EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT2_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT2_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT2_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT2_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT2_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT2_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT2_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT2_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT2_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT2_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.setBit<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.clearBit<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> GET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]
static inline bool GET_EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.getBit<EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT3_PLS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT3_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT3_PLS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT3_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT3_PLS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT3_PLS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT3_PLS,
           EC_PC_PMC_UPDATE_PSSCR_VT3_PLS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_PLS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT3_PLS]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]

//>> SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return o_data.insertFromRight<EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]

//>> GET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_PMC_UPDATE));
#endif
    return i_data.extractToRight<EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1,
           EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1]

//>> PREP_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG;
#endif
    return fapi2::getScom(i_target, EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]

//>> PUT_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return fapi2::putScom(i_target, EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]


//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]
static inline bool GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]
static inline bool GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.setBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& CLEAR_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.clearBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]
static inline bool GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.getBit<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& SET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return o_data.insertFromRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]
static inline fapi2::buffer<uint64_t>& GET_EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG));
#endif
    return i_data.extractToRight<EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS,
           EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_ACTION0_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]

//>> GET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_ACTION0_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_ACTION0_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_ACTION0_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION0_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_ACTION0_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG]


//>> SET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> SET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION0_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> GET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION0_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0,
           L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0]

//>> PREP_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2_L2MISC_L2CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_ACTION1_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]

//>> GET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2_L2MISC_L2CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2_L2MISC_L2CERRS_FIR_ACTION1_REG;
#endif
    return fapi2::getScom(i_target, L2_L2MISC_L2CERRS_FIR_ACTION1_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]

//>> PUT_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2_L2MISC_L2CERRS_FIR_ACTION1_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION1_REG));
#endif
    return fapi2::putScom(i_target, L2_L2MISC_L2CERRS_FIR_ACTION1_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG]


//>> SET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> SET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& SET_L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION1_REG));
#endif
    return o_data.insertFromRight<L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> GET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]
static inline fapi2::buffer<uint64_t>& GET_L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2_L2MISC_L2CERRS_FIR_ACTION1_REG));
#endif
    return i_data.extractToRight<L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1,
           L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1]

//>> PREP_[L2TRA_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_TRACE_HI_DATA_REG]

//>> GET_[L2TRA_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_TRACE_HI_DATA_REG;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_TRACE_HI_DATA_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_HI_DATA_REG]

//>> PUT_[L2TRA_TR0_TRACE_HI_DATA_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_TRACE_HI_DATA_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_HI_DATA_REG));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_TRACE_HI_DATA_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_TRACE_HI_DATA_REG]


//>> SET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> SET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_HI_DATA_REG));
#endif
    return o_data.insertFromRight<L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> GET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_TRACE_HI_DATA_REG));
#endif
    return i_data.extractToRight<L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA,
           L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA]

//>> PREP_[L2TRA_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR0_CONFIG_0]

//>> GET_[L2TRA_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR0_CONFIG_0;
#endif
    return fapi2::getScom(i_target, L2TRA_TR0_CONFIG_0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_0]

//>> PUT_[L2TRA_TR0_CONFIG_0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR0_CONFIG_0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_0));
#endif
    return fapi2::putScom(i_target, L2TRA_TR0_CONFIG_0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR0_CONFIG_0]


//>> SET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> SET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_0));
#endif
    return o_data.insertFromRight<L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> GET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR0_CONFIG_0));
#endif
    return i_data.extractToRight<L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63,
           L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63]

//>> PREP_[L2TRA_TR1_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L2TRA_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_9;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L2TRA_TR1_CONFIG_9]

//>> GET_[L2TRA_TR1_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L2TRA_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L2TRA_TR1_CONFIG_9;
#endif
    return fapi2::getScom(i_target, L2TRA_TR1_CONFIG_9, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9]

//>> PUT_[L2TRA_TR1_CONFIG_9]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L2TRA_TR1_CONFIG_9(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return fapi2::putScom(i_target, L2TRA_TR1_CONFIG_9, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L2TRA_TR1_CONFIG_9]


//>> SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> GET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]
static inline bool GET_L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]
static inline bool GET_L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK chip: %x, ec: %x",
             scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]

//>> GET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]

//>> GET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]

//>> GET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]

//>> GET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL,
           L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK,
           L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]
static inline bool GET_L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]

//>> GET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE,
           L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]
static inline bool GET_L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]
static inline bool GET_L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]
static inline bool GET_L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> GET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]
static inline bool GET_L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP]

//>> SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> GET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]
static inline bool GET_L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES]

//>> SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_SPARE_LT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.insertFromRight<L2TRA_TR1_CONFIG_9_SPARE_LT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& SET_L2TRA_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.setBit<L2TRA_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> CLEAR_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& CLEAR_L2TRA_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return o_data.clearBit<L2TRA_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> GET_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline fapi2::buffer<uint64_t>& GET_L2TRA_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.extractToRight<L2TRA_TR1_CONFIG_9_SPARE_LT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> GET_[L2TRA_TR1_CONFIG_9_SPARE_LT]
static inline bool GET_L2TRA_TR1_CONFIG_9_SPARE_LT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L2TRA_TR1_CONFIG_9));
#endif
    return i_data.getBit<L2TRA_TR1_CONFIG_9_SPARE_LT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_c Invalid dial access L2TRA_TR1_CONFIG_9_SPARE_LT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[L2TRA_TR1_CONFIG_9_SPARE_LT]

//>> PREP_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]

//>> GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG;
#endif
    return fapi2::getScom(i_target, L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]

//>> PUT_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return fapi2::putScom(i_target, L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]


//>> SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]

//>> SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]

//>> GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG]

//>> SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]

//>> SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]
static inline fapi2::buffer<uint64_t>& SET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return o_data.insertFromRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]

//>> GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]
static inline fapi2::buffer<uint64_t>& GET_L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG));
#endif
    return i_data.extractToRight<L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG,
           L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_c Invalid dial access L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
