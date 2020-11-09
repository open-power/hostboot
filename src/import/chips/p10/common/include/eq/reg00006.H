/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00006.H $           */
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

#ifndef __EQ_REG00006_H_
#define __EQ_REG00006_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_RW]

//>> GET_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_RW]

//>> PUT_[CPLT_CONF1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_RW]

//>> PREP_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_WO_CLEAR]

//>> GET_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_WO_CLEAR]

//>> PUT_[CPLT_CONF1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_WO_CLEAR]

//>> PREP_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CONF1_WO_OR]

//>> GET_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CONF1_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CONF1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CONF1_WO_OR]

//>> PUT_[CPLT_CONF1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CONF1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CONF1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CONF1_WO_OR]


//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_OCB_MH_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_PWR_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC,
           CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_QUAD_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> CLEAR_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]
static inline bool GET_CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_AMUX_EQ_VSEL_VMEAS_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> CLEAR_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]
static inline bool GET_CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_CALIBRATE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> CLEAR_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]
static inline bool GET_CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_ANEQ_VMEAS_MEASURE_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.setBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> CLEAR_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(
    fapi2::buffer<uint64_t>& i_data,
    uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]
static inline bool GET_CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CONF1_RW, CPLT_CONF1_WO_CLEAR, CPLT_CONF1_WO_OR));
#endif
    return i_data.getBit<CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC]

//>> PREP_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_RW]

//>> GET_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_RW;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_RW]

//>> PUT_[CPLT_CTRL1_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_RW]

//>> PREP_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_WO_CLEAR]

//>> GET_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_WO_CLEAR]

//>> PUT_[CPLT_CTRL1_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_WO_CLEAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_WO_CLEAR]

//>> PREP_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[CPLT_CTRL1_WO_OR]

//>> GET_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = CPLT_CTRL1_WO_OR;
#endif
    return fapi2::getScom(i_target, CPLT_CTRL1_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[CPLT_CTRL1_WO_OR]

//>> PUT_[CPLT_CTRL1_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_CPLT_CTRL1_WO_OR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return fapi2::putScom(i_target, CPLT_CTRL1_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[CPLT_CTRL1_WO_OR]


//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]
static inline bool GET_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION0_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION0_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION0_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION0_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION0_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION0_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION1_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION1_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION1_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION1_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION1_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION1_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION2_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION2_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION2_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION2_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION2_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION2_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION3_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION3_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION3_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION3_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION3_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION3_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION4_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION4_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION4_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION4_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION4_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION4_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION5_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION5_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION5_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION5_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION5_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION5_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION6_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION6_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION6_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION6_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION6_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION6_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION7_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION7_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION7_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION7_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION7_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION7_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION8_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION8_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION8_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION8_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION8_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION8_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION9_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION9_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION9_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION9_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION9_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION9_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION10_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION10_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION10_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION10_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION10_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION10_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION11_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION11_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION11_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION11_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION11_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION11_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION12_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION12_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION12_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION12_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION12_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION12_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION13_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION13_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION13_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION13_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION13_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION13_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> CLEAR_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_REGION14_FENCE_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> GET_[CPLT_CTRL1_REGION14_FENCE_DC]
static inline bool GET_CPLT_CTRL1_REGION14_FENCE_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_REGION14_FENCE_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_REGION14_FENCE_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_REGION14_FENCE_DC]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.insertFromRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> SET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& SET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.setBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> CLEAR_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& CLEAR_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return o_data.clearBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline fapi2::buffer<uint64_t>& GET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.extractToRight<CPLT_CTRL1_STG_ACT_EN_DC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> GET_[CPLT_CTRL1_STG_ACT_EN_DC]
static inline bool GET_CPLT_CTRL1_STG_ACT_EN_DC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(CPLT_CTRL1_RW, CPLT_CTRL1_WO_CLEAR, CPLT_CTRL1_WO_OR));
#endif
    return i_data.getBit<CPLT_CTRL1_STG_ACT_EN_DC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access CPLT_CTRL1_STG_ACT_EN_DC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[CPLT_CTRL1_STG_ACT_EN_DC]

//>> PREP_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_RW]

//>> GET_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_RW;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_RW]

//>> PUT_[LOCAL_XSTOP_MASK_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_RW]

//>> PREP_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> GET_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_CLEAR;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_WO_CLEAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> PUT_[LOCAL_XSTOP_MASK_WO_CLEAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_WO_CLEAR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_WO_CLEAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_WO_CLEAR]

//>> PREP_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[LOCAL_XSTOP_MASK_WO_OR]

//>> GET_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = LOCAL_XSTOP_MASK_WO_OR;
#endif
    return fapi2::getScom(i_target, LOCAL_XSTOP_MASK_WO_OR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_WO_OR]

//>> PUT_[LOCAL_XSTOP_MASK_WO_OR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_LOCAL_XSTOP_MASK_WO_OR(const fapi2::Target<K, M, V>& i_target,
        const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return fapi2::putScom(i_target, LOCAL_XSTOP_MASK_WO_OR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[LOCAL_XSTOP_MASK_WO_OR]


//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_01]

//>> CLEAR_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_01]

//>> GET_[LOCAL_XSTOP_MASK_01]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_01]

//>> GET_[LOCAL_XSTOP_MASK_01]
static inline bool GET_LOCAL_XSTOP_MASK_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_01]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_02]

//>> CLEAR_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_02]

//>> GET_[LOCAL_XSTOP_MASK_02]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_02]

//>> GET_[LOCAL_XSTOP_MASK_02]
static inline bool GET_LOCAL_XSTOP_MASK_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_02]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_03]

//>> CLEAR_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_03]

//>> GET_[LOCAL_XSTOP_MASK_03]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_03]

//>> GET_[LOCAL_XSTOP_MASK_03]
static inline bool GET_LOCAL_XSTOP_MASK_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_03]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_04]

//>> CLEAR_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_04]

//>> GET_[LOCAL_XSTOP_MASK_04]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_04]

//>> GET_[LOCAL_XSTOP_MASK_04]
static inline bool GET_LOCAL_XSTOP_MASK_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_04]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_05]

//>> CLEAR_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_05]

//>> GET_[LOCAL_XSTOP_MASK_05]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_05]

//>> GET_[LOCAL_XSTOP_MASK_05]
static inline bool GET_LOCAL_XSTOP_MASK_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_05]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_06]

//>> CLEAR_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_06]

//>> GET_[LOCAL_XSTOP_MASK_06]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_06]

//>> GET_[LOCAL_XSTOP_MASK_06]
static inline bool GET_LOCAL_XSTOP_MASK_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_06]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_07]

//>> CLEAR_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_07]

//>> GET_[LOCAL_XSTOP_MASK_07]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_07]

//>> GET_[LOCAL_XSTOP_MASK_07]
static inline bool GET_LOCAL_XSTOP_MASK_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_07]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_08]

//>> CLEAR_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_08]

//>> GET_[LOCAL_XSTOP_MASK_08]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_08]

//>> GET_[LOCAL_XSTOP_MASK_08]
static inline bool GET_LOCAL_XSTOP_MASK_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_08]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_09]

//>> CLEAR_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_09]

//>> GET_[LOCAL_XSTOP_MASK_09]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_09]

//>> GET_[LOCAL_XSTOP_MASK_09]
static inline bool GET_LOCAL_XSTOP_MASK_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_09]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_10]

//>> CLEAR_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_10]

//>> GET_[LOCAL_XSTOP_MASK_10]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_10]

//>> GET_[LOCAL_XSTOP_MASK_10]
static inline bool GET_LOCAL_XSTOP_MASK_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_10]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_11]

//>> CLEAR_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_11]

//>> GET_[LOCAL_XSTOP_MASK_11]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_11]

//>> GET_[LOCAL_XSTOP_MASK_11]
static inline bool GET_LOCAL_XSTOP_MASK_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_11]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_12]

//>> CLEAR_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_12]

//>> GET_[LOCAL_XSTOP_MASK_12]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_12]

//>> GET_[LOCAL_XSTOP_MASK_12]
static inline bool GET_LOCAL_XSTOP_MASK_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_12]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_13]

//>> CLEAR_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_13]

//>> GET_[LOCAL_XSTOP_MASK_13]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_13]

//>> GET_[LOCAL_XSTOP_MASK_13]
static inline bool GET_LOCAL_XSTOP_MASK_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_13]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_14]

//>> CLEAR_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_14]

//>> GET_[LOCAL_XSTOP_MASK_14]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_14]

//>> GET_[LOCAL_XSTOP_MASK_14]
static inline bool GET_LOCAL_XSTOP_MASK_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_14]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.insertFromRight<LOCAL_XSTOP_MASK_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> SET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& SET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.setBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[LOCAL_XSTOP_MASK_15]

//>> CLEAR_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& CLEAR_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return o_data.clearBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[LOCAL_XSTOP_MASK_15]

//>> GET_[LOCAL_XSTOP_MASK_15]
static inline fapi2::buffer<uint64_t>& GET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.extractToRight<LOCAL_XSTOP_MASK_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_15]

//>> GET_[LOCAL_XSTOP_MASK_15]
static inline bool GET_LOCAL_XSTOP_MASK_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(LOCAL_XSTOP_MASK_RW, LOCAL_XSTOP_MASK_WO_CLEAR, LOCAL_XSTOP_MASK_WO_OR));
#endif
    return i_data.getBit<LOCAL_XSTOP_MASK_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access LOCAL_XSTOP_MASK_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[LOCAL_XSTOP_MASK_15]

//>> PREP_[QME_PPEBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_PPEBAR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEBAR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_PPEBAR]

//>> GET_[QME_PPEBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_PPEBAR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_PPEBAR;
#endif
    return fapi2::getScom(i_target, QME_PPEBAR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_PPEBAR]

//>> PUT_[QME_PPEBAR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_PPEBAR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return fapi2::putScom(i_target, QME_PPEBAR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_PPEBAR]


//>> SET_[QME_PPEBAR_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEBAR_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return o_data.insertFromRight<QME_PPEBAR_BASE,
           QME_PPEBAR_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEBAR_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEBAR_BASE]

//>> SET_[QME_PPEBAR_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEBAR_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return o_data.insertFromRight<QME_PPEBAR_BASE,
           QME_PPEBAR_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEBAR_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEBAR_BASE]

//>> GET_[QME_PPEBAR_BASE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEBAR_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return i_data.extractToRight<QME_PPEBAR_BASE,
           QME_PPEBAR_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEBAR_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEBAR_BASE]

//>> SET_[QME_PPEBAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEBAR_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return o_data.insertFromRight<QME_PPEBAR_SIZE,
           QME_PPEBAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_PPEBAR_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEBAR_SIZE]

//>> SET_[QME_PPEBAR_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_PPEBAR_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return o_data.insertFromRight<QME_PPEBAR_SIZE,
           QME_PPEBAR_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_PPEBAR_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_PPEBAR_SIZE]

//>> GET_[QME_PPEBAR_SIZE]
static inline fapi2::buffer<uint64_t>& GET_QME_PPEBAR_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_PPEBAR));
#endif
    return i_data.extractToRight<QME_PPEBAR_SIZE,
           QME_PPEBAR_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_PPEBAR_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_PPEBAR_SIZE]

//>> PREP_[QME_QHTMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_QHTMEM(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QHTMEM;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_QHTMEM]

//>> GET_[QME_QHTMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_QHTMEM(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_QHTMEM;
#endif
    return fapi2::getScom(i_target, QME_QHTMEM, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_QHTMEM]

//>> PUT_[QME_QHTMEM]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_QHTMEM(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return fapi2::putScom(i_target, QME_QHTMEM, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_QHTMEM]


//>> SET_[QME_QHTMEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_ALLOC]

//>> SET_[QME_QHTMEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_ALLOC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_ALLOC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_ALLOC]

//>> SET_[QME_QHTMEM_ALLOC]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.setBit<QME_QHTMEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_ALLOC]

//>> CLEAR_[QME_QHTMEM_ALLOC]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QHTMEM_ALLOC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.clearBit<QME_QHTMEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QHTMEM_ALLOC]

//>> GET_[QME_QHTMEM_ALLOC]
static inline fapi2::buffer<uint64_t>& GET_QME_QHTMEM_ALLOC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<QME_QHTMEM_ALLOC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_ALLOC]

//>> GET_[QME_QHTMEM_ALLOC]
static inline bool GET_QME_QHTMEM_ALLOC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.getBit<QME_QHTMEM_ALLOC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QHTMEM_ALLOC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_ALLOC]

//>> SET_[QME_QHTMEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_SCOPE,
           QME_QHTMEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHTMEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_SCOPE]

//>> SET_[QME_QHTMEM_SCOPE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_SCOPE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_SCOPE,
           QME_QHTMEM_SCOPE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHTMEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_SCOPE]

//>> GET_[QME_QHTMEM_SCOPE]
static inline fapi2::buffer<uint64_t>& GET_QME_QHTMEM_SCOPE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<QME_QHTMEM_SCOPE,
           QME_QHTMEM_SCOPE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHTMEM_SCOPE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_SCOPE]

//>> SET_[QME_QHTMEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_PRIORITY]

//>> SET_[QME_QHTMEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_PRIORITY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_PRIORITY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_PRIORITY]

//>> SET_[QME_QHTMEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.setBit<QME_QHTMEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_PRIORITY]

//>> CLEAR_[QME_QHTMEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& CLEAR_QME_QHTMEM_PRIORITY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.clearBit<QME_QHTMEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[QME_QHTMEM_PRIORITY]

//>> GET_[QME_QHTMEM_PRIORITY]
static inline fapi2::buffer<uint64_t>& GET_QME_QHTMEM_PRIORITY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<QME_QHTMEM_PRIORITY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_PRIORITY]

//>> GET_[QME_QHTMEM_PRIORITY]
static inline bool GET_QME_QHTMEM_PRIORITY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.getBit<QME_QHTMEM_PRIORITY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access QME_QHTMEM_PRIORITY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_PRIORITY]

//>> SET_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_QME_QHTMEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<P10_20_QME_QHTMEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> SET_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_QME_QHTMEM_SIZE_SMALL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<P10_20_QME_QHTMEM_SIZE_SMALL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> SET_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& SET_P10_20_QME_QHTMEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.setBit<P10_20_QME_QHTMEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> CLEAR_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& CLEAR_P10_20_QME_QHTMEM_SIZE_SMALL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.clearBit<P10_20_QME_QHTMEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> GET_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline fapi2::buffer<uint64_t>& GET_P10_20_QME_QHTMEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<P10_20_QME_QHTMEM_SIZE_SMALL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> GET_[P10_20_QME_QHTMEM_SIZE_SMALL]
static inline bool GET_P10_20_QME_QHTMEM_SIZE_SMALL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::failOn(0xa, 0x10));
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.getBit<P10_20_QME_QHTMEM_SIZE_SMALL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access P10_20_QME_QHTMEM_SIZE_SMALL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[P10_20_QME_QHTMEM_SIZE_SMALL]

//>> SET_[QME_QHTMEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_BASE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_BASE,
           QME_QHTMEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHTMEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_BASE]

//>> SET_[QME_QHTMEM_BASE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_BASE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_BASE,
           QME_QHTMEM_BASE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHTMEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_BASE]

//>> GET_[QME_QHTMEM_BASE]
static inline fapi2::buffer<uint64_t>& GET_QME_QHTMEM_BASE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<QME_QHTMEM_BASE,
           QME_QHTMEM_BASE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHTMEM_BASE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_BASE]

//>> SET_[QME_QHTMEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_SIZE,
           QME_QHTMEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_QHTMEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_SIZE]

//>> SET_[QME_QHTMEM_SIZE]
static inline fapi2::buffer<uint64_t>& SET_QME_QHTMEM_SIZE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return o_data.insertFromRight<QME_QHTMEM_SIZE,
           QME_QHTMEM_SIZE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_QHTMEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_QHTMEM_SIZE]

//>> GET_[QME_QHTMEM_SIZE]
static inline fapi2::buffer<uint64_t>& GET_QME_QHTMEM_SIZE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_QHTMEM));
#endif
    return i_data.extractToRight<QME_QHTMEM_SIZE,
           QME_QHTMEM_SIZE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_QHTMEM_SIZE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_QHTMEM_SIZE]

//>> PREP_[QME_RCTAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RCTAR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCTAR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RCTAR2]

//>> GET_[QME_RCTAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RCTAR2(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RCTAR2;
#endif
    return fapi2::getScom(i_target, QME_RCTAR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RCTAR2]

//>> PUT_[QME_RCTAR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RCTAR2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RCTAR2));
#endif
    return fapi2::putScom(i_target, QME_RCTAR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RCTAR2]


//>> SET_[QME_RCTAR2_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RCTAR2_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR2));
#endif
    return o_data.insertFromRight<QME_RCTAR2_DATA,
           QME_RCTAR2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RCTAR2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCTAR2_DATA]

//>> SET_[QME_RCTAR2_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_RCTAR2_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR2));
#endif
    return o_data.insertFromRight<QME_RCTAR2_DATA,
           QME_RCTAR2_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RCTAR2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RCTAR2_DATA]

//>> GET_[QME_RCTAR2_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_RCTAR2_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RCTAR2));
#endif
    return i_data.extractToRight<QME_RCTAR2_DATA,
           QME_RCTAR2_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RCTAR2_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RCTAR2_DATA]

//>> PREP_[QME_SCOM_PBTXTR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_PBTXTR3(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_PBTXTR3;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_PBTXTR3]

//>> GET_[QME_SCOM_PBTXTR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_PBTXTR3(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_PBTXTR3;
#endif
    return fapi2::getScom(i_target, QME_SCOM_PBTXTR3, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3]

//>> PUT_[QME_SCOM_PBTXTR3]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_PBTXTR3(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return fapi2::putScom(i_target, QME_SCOM_PBTXTR3, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_PBTXTR3]


//>> SET_[QME_SCOM_PBTXTR3_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_VALID(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_VALID,
           QME_SCOM_PBTXTR3_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_VALID]

//>> SET_[QME_SCOM_PBTXTR3_VALID]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_VALID(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_VALID,
           QME_SCOM_PBTXTR3_VALID_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_VALID]

//>> GET_[QME_SCOM_PBTXTR3_VALID]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_VALID(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_VALID,
           QME_SCOM_PBTXTR3_VALID_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_VALID chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_VALID]

//>> SET_[QME_SCOM_PBTXTR3_0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_0,
           QME_SCOM_PBTXTR3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_0]

//>> SET_[QME_SCOM_PBTXTR3_0]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_0,
           QME_SCOM_PBTXTR3_0_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_0]

//>> GET_[QME_SCOM_PBTXTR3_0]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_0,
           QME_SCOM_PBTXTR3_0_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_0]

//>> SET_[QME_SCOM_PBTXTR3_1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_1,
           QME_SCOM_PBTXTR3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_1]

//>> SET_[QME_SCOM_PBTXTR3_1]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_1,
           QME_SCOM_PBTXTR3_1_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_1]

//>> GET_[QME_SCOM_PBTXTR3_1]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_1,
           QME_SCOM_PBTXTR3_1_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_1]

//>> SET_[QME_SCOM_PBTXTR3_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_2,
           QME_SCOM_PBTXTR3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_2]

//>> SET_[QME_SCOM_PBTXTR3_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_2,
           QME_SCOM_PBTXTR3_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_2]

//>> GET_[QME_SCOM_PBTXTR3_2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_2,
           QME_SCOM_PBTXTR3_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_2]

//>> SET_[QME_SCOM_PBTXTR3_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_3,
           QME_SCOM_PBTXTR3_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_3]

//>> SET_[QME_SCOM_PBTXTR3_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_3,
           QME_SCOM_PBTXTR3_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_3]

//>> GET_[QME_SCOM_PBTXTR3_3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_3,
           QME_SCOM_PBTXTR3_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_3]

//>> SET_[QME_SCOM_PBTXTR3_4]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_4,
           QME_SCOM_PBTXTR3_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_4]

//>> SET_[QME_SCOM_PBTXTR3_4]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_4,
           QME_SCOM_PBTXTR3_4_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_4]

//>> GET_[QME_SCOM_PBTXTR3_4]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_4,
           QME_SCOM_PBTXTR3_4_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_4]

//>> SET_[QME_SCOM_PBTXTR3_5]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_5,
           QME_SCOM_PBTXTR3_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_5]

//>> SET_[QME_SCOM_PBTXTR3_5]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_5,
           QME_SCOM_PBTXTR3_5_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_5]

//>> GET_[QME_SCOM_PBTXTR3_5]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_5,
           QME_SCOM_PBTXTR3_5_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_5]

//>> SET_[QME_SCOM_PBTXTR3_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_6,
           QME_SCOM_PBTXTR3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_6]

//>> SET_[QME_SCOM_PBTXTR3_6]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_6,
           QME_SCOM_PBTXTR3_6_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_6]

//>> GET_[QME_SCOM_PBTXTR3_6]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_6,
           QME_SCOM_PBTXTR3_6_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_6]

//>> SET_[QME_SCOM_PBTXTR3_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_7,
           QME_SCOM_PBTXTR3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_PBTXTR3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_7]

//>> SET_[QME_SCOM_PBTXTR3_7]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_PBTXTR3_7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return o_data.insertFromRight<QME_SCOM_PBTXTR3_7,
           QME_SCOM_PBTXTR3_7_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_PBTXTR3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_PBTXTR3_7]

//>> GET_[QME_SCOM_PBTXTR3_7]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_PBTXTR3_7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_PBTXTR3));
#endif
    return i_data.extractToRight<QME_SCOM_PBTXTR3_7,
           QME_SCOM_PBTXTR3_7_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_PBTXTR3_7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_PBTXTR3_7]

//>> PREP_[QME_SCOM_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIRAMEDR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMEDR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIRAMEDR]

//>> GET_[QME_SCOM_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIRAMEDR(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIRAMEDR;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIRAMEDR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIRAMEDR]

//>> PUT_[QME_SCOM_XIRAMEDR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIRAMEDR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIRAMEDR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIRAMEDR]


//>> SET_[QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMEDR_IR]

//>> SET_[QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMEDR_IR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMEDR_IR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMEDR_IR]

//>> GET_[QME_SCOM_XIRAMEDR_IR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMEDR_IR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMEDR_IR,
           QME_SCOM_XIRAMEDR_IR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_IR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMEDR_IR]

//>> SET_[QME_SCOM_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMEDR_EDR,
           QME_SCOM_XIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_EDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMEDR_EDR]

//>> SET_[QME_SCOM_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIRAMEDR_EDR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return o_data.insertFromRight<QME_SCOM_XIRAMEDR_EDR,
           QME_SCOM_XIRAMEDR_EDR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_EDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIRAMEDR_EDR]

//>> GET_[QME_SCOM_XIRAMEDR_EDR]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIRAMEDR_EDR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIRAMEDR));
#endif
    return i_data.extractToRight<QME_SCOM_XIRAMEDR_EDR,
           QME_SCOM_XIRAMEDR_EDR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIRAMEDR_EDR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIRAMEDR_EDR]

//>> PREP_[QME_SCOM_XIVDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIVDR2(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR2;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIVDR2]

//>> GET_[QME_SCOM_XIVDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIVDR2(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR2;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIVDR2, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIVDR2]

//>> PUT_[QME_SCOM_XIVDR2]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIVDR2(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIVDR2, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIVDR2]


//>> SET_[QME_SCOM_XIVDR2_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR2_2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR2_2,
           QME_SCOM_XIVDR2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR2_2]

//>> SET_[QME_SCOM_XIVDR2_2]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR2_2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR2_2,
           QME_SCOM_XIVDR2_2_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR2_2]

//>> GET_[QME_SCOM_XIVDR2_2]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR2_2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR2_2,
           QME_SCOM_XIVDR2_2_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR2_2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR2_2]

//>> SET_[QME_SCOM_XIVDR2_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR2_3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR2_3,
           QME_SCOM_XIVDR2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR2_3]

//>> SET_[QME_SCOM_XIVDR2_3]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR2_3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR2_3,
           QME_SCOM_XIVDR2_3_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR2_3]

//>> GET_[QME_SCOM_XIVDR2_3]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR2_3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR2));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR2_3,
           QME_SCOM_XIVDR2_3_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR2_3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR2_3]


//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
