/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/eq/reg00008.H $           */
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

#ifndef __EQ_REG00008_H_
#define __EQ_REG00008_H_

#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> PREP_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[EPS_FIR_LOCAL_ACTION0]

//>> GET_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = EPS_FIR_LOCAL_ACTION0;
#endif
    return fapi2::getScom(i_target, EPS_FIR_LOCAL_ACTION0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0]

//>> PUT_[EPS_FIR_LOCAL_ACTION0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_EPS_FIR_LOCAL_ACTION0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return fapi2::putScom(i_target, EPS_FIR_LOCAL_ACTION0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[EPS_FIR_LOCAL_ACTION0]


//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_00]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[EPS_FIR_LOCAL_ACTION0_00]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_00,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_00]

//>> GET_[EPS_FIR_LOCAL_ACTION0_00]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_00(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_00>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_00 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_00]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_01]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[EPS_FIR_LOCAL_ACTION0_01]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_01,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_01]

//>> GET_[EPS_FIR_LOCAL_ACTION0_01]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_01(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_01>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_01 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_01]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_02]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[EPS_FIR_LOCAL_ACTION0_02]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_02,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_02]

//>> GET_[EPS_FIR_LOCAL_ACTION0_02]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_02(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_02>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_02 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_02]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_03]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[EPS_FIR_LOCAL_ACTION0_03]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_03,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_03]

//>> GET_[EPS_FIR_LOCAL_ACTION0_03]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_03(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_03>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_03 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_03]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_04]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[EPS_FIR_LOCAL_ACTION0_04]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_04,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_04]

//>> GET_[EPS_FIR_LOCAL_ACTION0_04]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_04(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_04>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_04 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_04]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_05]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[EPS_FIR_LOCAL_ACTION0_05]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_05,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_05]

//>> GET_[EPS_FIR_LOCAL_ACTION0_05]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_05(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_05>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_05 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_05]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_06]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[EPS_FIR_LOCAL_ACTION0_06]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_06,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_06]

//>> GET_[EPS_FIR_LOCAL_ACTION0_06]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_06(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_06>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_06 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_06]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_07]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[EPS_FIR_LOCAL_ACTION0_07]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_07,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_07]

//>> GET_[EPS_FIR_LOCAL_ACTION0_07]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_07(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_07>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_07 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_07]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_08]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[EPS_FIR_LOCAL_ACTION0_08]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_08,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_08]

//>> GET_[EPS_FIR_LOCAL_ACTION0_08]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_08(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_08>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_08 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_08]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_09]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[EPS_FIR_LOCAL_ACTION0_09]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_09,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_09]

//>> GET_[EPS_FIR_LOCAL_ACTION0_09]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_09(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_09>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_09 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_09]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_10]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[EPS_FIR_LOCAL_ACTION0_10]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_10]

//>> GET_[EPS_FIR_LOCAL_ACTION0_10]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_10]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_11]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[EPS_FIR_LOCAL_ACTION0_11]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_11]

//>> GET_[EPS_FIR_LOCAL_ACTION0_11]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_11]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_12]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[EPS_FIR_LOCAL_ACTION0_12]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_12]

//>> GET_[EPS_FIR_LOCAL_ACTION0_12]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_12]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_13]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[EPS_FIR_LOCAL_ACTION0_13]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_13]

//>> GET_[EPS_FIR_LOCAL_ACTION0_13]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_13]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_14]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[EPS_FIR_LOCAL_ACTION0_14]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_14]

//>> GET_[EPS_FIR_LOCAL_ACTION0_14]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_14]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_15]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[EPS_FIR_LOCAL_ACTION0_15]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_15,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_15]

//>> GET_[EPS_FIR_LOCAL_ACTION0_15]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_15(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_15>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_15 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_15]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_16]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[EPS_FIR_LOCAL_ACTION0_16]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_16,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_16]

//>> GET_[EPS_FIR_LOCAL_ACTION0_16]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_16(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_16>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_16 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_16]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_17]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[EPS_FIR_LOCAL_ACTION0_17]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_17,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_17]

//>> GET_[EPS_FIR_LOCAL_ACTION0_17]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_17(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_17>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_17 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_17]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_18]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[EPS_FIR_LOCAL_ACTION0_18]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_18,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_18]

//>> GET_[EPS_FIR_LOCAL_ACTION0_18]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_18(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_18>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_18 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_18]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_19]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[EPS_FIR_LOCAL_ACTION0_19]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_19,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_19]

//>> GET_[EPS_FIR_LOCAL_ACTION0_19]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_19(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_19>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_19 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_19]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_20]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[EPS_FIR_LOCAL_ACTION0_20]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_20,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_20]

//>> GET_[EPS_FIR_LOCAL_ACTION0_20]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_20(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_20>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_20 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_20]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_21]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[EPS_FIR_LOCAL_ACTION0_21]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_21,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_21]

//>> GET_[EPS_FIR_LOCAL_ACTION0_21]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_21(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_21>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_21 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_21]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_22]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[EPS_FIR_LOCAL_ACTION0_22]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_22,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_22]

//>> GET_[EPS_FIR_LOCAL_ACTION0_22]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_22(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_22>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_22 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_22]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_23]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[EPS_FIR_LOCAL_ACTION0_23]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_23,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_23]

//>> GET_[EPS_FIR_LOCAL_ACTION0_23]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_23(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_23>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_23 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_23]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_24]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[EPS_FIR_LOCAL_ACTION0_24]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_24,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_24]

//>> GET_[EPS_FIR_LOCAL_ACTION0_24]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_24(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_24>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_24 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_24]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_25]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[EPS_FIR_LOCAL_ACTION0_25]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_25,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_25]

//>> GET_[EPS_FIR_LOCAL_ACTION0_25]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_25(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_25>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_25 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_25]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_26]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[EPS_FIR_LOCAL_ACTION0_26]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_26,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_26]

//>> GET_[EPS_FIR_LOCAL_ACTION0_26]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_26(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_26>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_26 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_26]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_27]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[EPS_FIR_LOCAL_ACTION0_27]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_27,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_27]

//>> GET_[EPS_FIR_LOCAL_ACTION0_27]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_27(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_27>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_27 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_27]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_28]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[EPS_FIR_LOCAL_ACTION0_28]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_28,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_28]

//>> GET_[EPS_FIR_LOCAL_ACTION0_28]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_28(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_28>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_28 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_28]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_29]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[EPS_FIR_LOCAL_ACTION0_29]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_29,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_29]

//>> GET_[EPS_FIR_LOCAL_ACTION0_29]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_29(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_29>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_29 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_29]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_30]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[EPS_FIR_LOCAL_ACTION0_30]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_30,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_30]

//>> GET_[EPS_FIR_LOCAL_ACTION0_30]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_30(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_30>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_30 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_30]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_31]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[EPS_FIR_LOCAL_ACTION0_31]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_31,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_31]

//>> GET_[EPS_FIR_LOCAL_ACTION0_31]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_31(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_31>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_31 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_31]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_32]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[EPS_FIR_LOCAL_ACTION0_32]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_32,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_32]

//>> GET_[EPS_FIR_LOCAL_ACTION0_32]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_32(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_32>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_32 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_32]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_33]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[EPS_FIR_LOCAL_ACTION0_33]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_33,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_33]

//>> GET_[EPS_FIR_LOCAL_ACTION0_33]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_33(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_33>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_33 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_33]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_34]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[EPS_FIR_LOCAL_ACTION0_34]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_34,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_34]

//>> GET_[EPS_FIR_LOCAL_ACTION0_34]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_34(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_34>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_34 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_34]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_35]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[EPS_FIR_LOCAL_ACTION0_35]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_35,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_35]

//>> GET_[EPS_FIR_LOCAL_ACTION0_35]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_35(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_35>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_35 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_35]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_36]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[EPS_FIR_LOCAL_ACTION0_36]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_36,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_36]

//>> GET_[EPS_FIR_LOCAL_ACTION0_36]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_36(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_36>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_36 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_36]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_37]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[EPS_FIR_LOCAL_ACTION0_37]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_37,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_37]

//>> GET_[EPS_FIR_LOCAL_ACTION0_37]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_37(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_37>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_37 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_37]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_38]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[EPS_FIR_LOCAL_ACTION0_38]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_38,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_38]

//>> GET_[EPS_FIR_LOCAL_ACTION0_38]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_38(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_38>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_38 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_38]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_39]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[EPS_FIR_LOCAL_ACTION0_39]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_39,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_39]

//>> GET_[EPS_FIR_LOCAL_ACTION0_39]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_39(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_39>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_39 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_39]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_40]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[EPS_FIR_LOCAL_ACTION0_40]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_40,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_40]

//>> GET_[EPS_FIR_LOCAL_ACTION0_40]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_40(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_40>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_40 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_40]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_41]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[EPS_FIR_LOCAL_ACTION0_41]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_41,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_41]

//>> GET_[EPS_FIR_LOCAL_ACTION0_41]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_41(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_41>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_41 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_41]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_42]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[EPS_FIR_LOCAL_ACTION0_42]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_42,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_42]

//>> GET_[EPS_FIR_LOCAL_ACTION0_42]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_42(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_42>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_42 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_42]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_43]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[EPS_FIR_LOCAL_ACTION0_43]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_43,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_43]

//>> GET_[EPS_FIR_LOCAL_ACTION0_43]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_43(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_43>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_43 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_43]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_44]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[EPS_FIR_LOCAL_ACTION0_44]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_44,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_44]

//>> GET_[EPS_FIR_LOCAL_ACTION0_44]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_44(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_44>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_44 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_44]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_45]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[EPS_FIR_LOCAL_ACTION0_45]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_45,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_45]

//>> GET_[EPS_FIR_LOCAL_ACTION0_45]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_45(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_45>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_45 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_45]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_46]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[EPS_FIR_LOCAL_ACTION0_46]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_46,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_46]

//>> GET_[EPS_FIR_LOCAL_ACTION0_46]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_46(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_46>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_46 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_46]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_47]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[EPS_FIR_LOCAL_ACTION0_47]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_47,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_47]

//>> GET_[EPS_FIR_LOCAL_ACTION0_47]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_47(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_47>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_47 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_47]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_48]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[EPS_FIR_LOCAL_ACTION0_48]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_48,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_48]

//>> GET_[EPS_FIR_LOCAL_ACTION0_48]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_48(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_48>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_48 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_48]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_49]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[EPS_FIR_LOCAL_ACTION0_49]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_49,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_49]

//>> GET_[EPS_FIR_LOCAL_ACTION0_49]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_49(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_49>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_49 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_49]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_50]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[EPS_FIR_LOCAL_ACTION0_50]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_50,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_50]

//>> GET_[EPS_FIR_LOCAL_ACTION0_50]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_50(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_50>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_50 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_50]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_51]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[EPS_FIR_LOCAL_ACTION0_51]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_51,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_51]

//>> GET_[EPS_FIR_LOCAL_ACTION0_51]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_51(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_51>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_51 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_51]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_52]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[EPS_FIR_LOCAL_ACTION0_52]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_52,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_52]

//>> GET_[EPS_FIR_LOCAL_ACTION0_52]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_52(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_52>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_52 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_52]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_53]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[EPS_FIR_LOCAL_ACTION0_53]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_53,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_53]

//>> GET_[EPS_FIR_LOCAL_ACTION0_53]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_53(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_53>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_53 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_53]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_54]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[EPS_FIR_LOCAL_ACTION0_54]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_54,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_54]

//>> GET_[EPS_FIR_LOCAL_ACTION0_54]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_54(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_54>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_54 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_54]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_55]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[EPS_FIR_LOCAL_ACTION0_55]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_55,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_55]

//>> GET_[EPS_FIR_LOCAL_ACTION0_55]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_55(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_55>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_55 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_55]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_56]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[EPS_FIR_LOCAL_ACTION0_56]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_56,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_56]

//>> GET_[EPS_FIR_LOCAL_ACTION0_56]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_56(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_56>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_56 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_56]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_57]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[EPS_FIR_LOCAL_ACTION0_57]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_57,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_57]

//>> GET_[EPS_FIR_LOCAL_ACTION0_57]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_57(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_57>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_57 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_57]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_58]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[EPS_FIR_LOCAL_ACTION0_58]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_58,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_58]

//>> GET_[EPS_FIR_LOCAL_ACTION0_58]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_58(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_58>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_58 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_58]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_59]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[EPS_FIR_LOCAL_ACTION0_59]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_59,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_59]

//>> GET_[EPS_FIR_LOCAL_ACTION0_59]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_59(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_59>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_59 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_59]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_60]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[EPS_FIR_LOCAL_ACTION0_60]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_60,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_60]

//>> GET_[EPS_FIR_LOCAL_ACTION0_60]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_60(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_60>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_60 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_60]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_61]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[EPS_FIR_LOCAL_ACTION0_61]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_61,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_61]

//>> GET_[EPS_FIR_LOCAL_ACTION0_61]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_61(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_61>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_61 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_61]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_62]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[EPS_FIR_LOCAL_ACTION0_62]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_62,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_62]

//>> GET_[EPS_FIR_LOCAL_ACTION0_62]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_62(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_62>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_62 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_62]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.insertFromRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> SET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& SET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.setBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[EPS_FIR_LOCAL_ACTION0_63]

//>> CLEAR_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& CLEAR_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return o_data.clearBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[EPS_FIR_LOCAL_ACTION0_63]
static inline fapi2::buffer<uint64_t>& GET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.extractToRight<EPS_FIR_LOCAL_ACTION0_63,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_63]

//>> GET_[EPS_FIR_LOCAL_ACTION0_63]
static inline bool GET_EPS_FIR_LOCAL_ACTION0_63(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(EPS_FIR_LOCAL_ACTION0));
#endif
    return i_data.getBit<EPS_FIR_LOCAL_ACTION0_63>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access EPS_FIR_LOCAL_ACTION0_63 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[EPS_FIR_LOCAL_ACTION0_63]

//>> PREP_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_ERROR_REG(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[ERROR_REG]

//>> GET_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_ERROR_REG(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = ERROR_REG;
#endif
    return fapi2::getScom(i_target, ERROR_REG, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[ERROR_REG]

//>> PUT_[ERROR_REG]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_ERROR_REG(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return fapi2::putScom(i_target, ERROR_REG, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[ERROR_REG]


//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CE_ERROR]

//>> CLEAR_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> GET_[ERROR_REG_CE_ERROR]
static inline bool GET_ERROR_REG_CE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CE_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ERRORS(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ERRORS]

//>> GET_[ERROR_REG_CHIPLET_ERRORS]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ERRORS(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ERRORS,
           ERROR_REG_CHIPLET_ERRORS_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CHIPLET_ERRORS chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ERRORS]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DATA_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> GET_[ERROR_REG_DATA_BUFFER_ERROR]
static inline bool GET_ERROR_REG_DATA_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DATA_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_DATA_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DATA_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDR_BUFFER_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> GET_[ERROR_REG_ADDR_BUFFER_ERROR]
static inline bool GET_ERROR_REG_ADDR_BUFFER_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDR_BUFFER_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_ADDR_BUFFER_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDR_BUFFER_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_FSM_ERROR]

//>> CLEAR_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> GET_[ERROR_REG_PCB_FSM_ERROR]
static inline bool GET_ERROR_REG_PCB_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_PCB_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_FSM_ERROR]

//>> CLEAR_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> GET_[ERROR_REG_CL_FSM_ERROR]
static inline bool GET_ERROR_REG_CL_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CL_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_RX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_RX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_RX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_RX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_INT_RX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_RX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TX_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> GET_[ERROR_REG_INT_TX_FSM_ERROR]
static inline bool GET_ERROR_REG_INT_TX_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TX_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_INT_TX_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TX_FSM_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INT_TYPE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INT_TYPE_ERROR]

//>> CLEAR_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INT_TYPE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> GET_[ERROR_REG_INT_TYPE_ERROR]
static inline bool GET_ERROR_REG_INT_TYPE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INT_TYPE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_INT_TYPE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INT_TYPE_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CL_DATA_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CL_DATA_ERROR]

//>> CLEAR_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CL_DATA_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> GET_[ERROR_REG_CL_DATA_ERROR]
static inline bool GET_ERROR_REG_CL_DATA_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CL_DATA_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CL_DATA_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CL_DATA_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_INFO_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_INFO_ERROR]

//>> CLEAR_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_INFO_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> GET_[ERROR_REG_INFO_ERROR]
static inline bool GET_ERROR_REG_INFO_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_INFO_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_INFO_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_INFO_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_SEQ_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_SEQ_ERROR]

//>> CLEAR_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_SEQ_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> GET_[ERROR_REG_SEQ_ERROR]
static inline bool GET_ERROR_REG_SEQ_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_SEQ_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_SEQ_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_SEQ_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]
static inline bool GET_ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PCB_INTERFACE_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> GET_[ERROR_REG_PCB_INTERFACE_ERROR]
static inline bool GET_ERROR_REG_PCB_INTERFACE_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_PCB_INTERFACE_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_PCB_INTERFACE_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PCB_INTERFACE_ERROR]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CHIPLET_OFFLINE]

//>> CLEAR_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CHIPLET_OFFLINE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> GET_[ERROR_REG_CHIPLET_OFFLINE]
static inline bool GET_ERROR_REG_CHIPLET_OFFLINE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CHIPLET_OFFLINE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CHIPLET_OFFLINE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CHIPLET_OFFLINE]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_EDRAM_SEQUENCE_ERR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]
static inline bool GET_ERROR_REG_EDRAM_SEQUENCE_ERR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_EDRAM_SEQUENCE_ERR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_EDRAM_SEQUENCE_ERR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_EDRAM_SEQUENCE_ERR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CTRL_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CTRL_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CTRL_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CTRL_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CTRL_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_ADDRESS_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_ADDRESS_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_ADDRESS_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_ADDRESS_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_ADDRESS_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_TIMEOUT_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_TIMEOUT_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_TIMEOUT_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_TIMEOUT_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_TIMEOUT_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_CONFIG_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_CONFIG_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_CONFIG_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_CONFIG_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_CONFIG_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_DIV_REG_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> GET_[ERROR_REG_DIV_REG_PARITY_ERROR]
static inline bool GET_ERROR_REG_DIV_REG_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_DIV_REG_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_DIV_REG_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_DIV_REG_PARITY_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_PLL_UNLOCK_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> GET_[ERROR_REG_PLL_UNLOCK_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_PLL_UNLOCK_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_PLL_UNLOCK_ERROR,
           ERROR_REG_PLL_UNLOCK_ERROR_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_PLL_UNLOCK_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_PLL_UNLOCK_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_INTERFACE_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_INTERFACE_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_INTERFACE_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_QME_INTERFACE_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_INTERFACE_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_DATA_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_DATA_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_DATA_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_DATA_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_QME_DATA_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_DATA_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_ADDR_PARITY_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]
static inline bool GET_ERROR_REG_QME_ADDR_PARITY_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_ADDR_PARITY_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_QME_ADDR_PARITY_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_ADDR_PARITY_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.insertFromRight<ERROR_REG_QME_FSM_ERROR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> SET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& SET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.setBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[ERROR_REG_QME_FSM_ERROR]

//>> CLEAR_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& CLEAR_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return o_data.clearBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline fapi2::buffer<uint64_t>& GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.extractToRight<ERROR_REG_QME_FSM_ERROR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> GET_[ERROR_REG_QME_FSM_ERROR]
static inline bool GET_ERROR_REG_QME_FSM_ERROR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(ERROR_REG));
#endif
    return i_data.getBit<ERROR_REG_QME_FSM_ERROR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access ERROR_REG_QME_FSM_ERROR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[ERROR_REG_QME_FSM_ERROR]

//>> PREP_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_OPCG_REG0(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG0;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[OPCG_REG0]

//>> GET_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_OPCG_REG0(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = OPCG_REG0;
#endif
    return fapi2::getScom(i_target, OPCG_REG0, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[OPCG_REG0]

//>> PUT_[OPCG_REG0]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_OPCG_REG0(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return fapi2::putScom(i_target, OPCG_REG0, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[OPCG_REG0]


//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_MODE]

//>> CLEAR_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUNN_MODE]

//>> GET_[OPCG_REG0_RUNN_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUNN_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_MODE]

//>> GET_[OPCG_REG0_RUNN_MODE]
static inline bool GET_OPCG_REG0_RUNN_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUNN_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_RUNN_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_MODE]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_GO,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_GO]

//>> CLEAR_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_GO]

//>> GET_[OPCG_REG0_OPCG_GO]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_GO,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_GO]

//>> GET_[OPCG_REG0_OPCG_GO]
static inline bool GET_OPCG_REG0_OPCG_GO(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_GO>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_OPCG_GO chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_GO]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_SCAN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_SCAN0,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_SCAN0]

//>> CLEAR_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_SCAN0]

//>> GET_[OPCG_REG0_RUN_SCAN0]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_SCAN0,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_SCAN0]

//>> GET_[OPCG_REG0_RUN_SCAN0]
static inline bool GET_OPCG_REG0_RUN_SCAN0(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_SCAN0>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_RUN_SCAN0 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_SCAN0]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_SCAN0_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_SCAN0_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_SCAN0_MODE]

//>> CLEAR_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_SCAN0_MODE]

//>> GET_[OPCG_REG0_SCAN0_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_SCAN0_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_SCAN0_MODE]

//>> GET_[OPCG_REG0_SCAN0_MODE]
static inline bool GET_OPCG_REG0_SCAN0_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_SCAN0_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_SCAN0_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_SCAN0_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> CLEAR_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_IN_SLAVE_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]
static inline bool GET_OPCG_REG0_OPCG_IN_SLAVE_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_IN_SLAVE_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_SLAVE_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_SLAVE_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> CLEAR_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_IN_MASTER_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]
static inline bool GET_OPCG_REG0_OPCG_IN_MASTER_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_IN_MASTER_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_OPCG_IN_MASTER_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_IN_MASTER_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_KEEP_MS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_KEEP_MS_MODE,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_KEEP_MS_MODE]

//>> CLEAR_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_KEEP_MS_MODE]

//>> GET_[OPCG_REG0_KEEP_MS_MODE]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_KEEP_MS_MODE,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_KEEP_MS_MODE]

//>> GET_[OPCG_REG0_KEEP_MS_MODE]
static inline bool GET_OPCG_REG0_KEEP_MS_MODE(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_KEEP_MS_MODE>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_KEEP_MS_MODE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_KEEP_MS_MODE]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]
static inline bool GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]
static inline bool GET_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> CLEAR_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]
static inline bool GET_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_OPCG_ON_UPDATE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_UPDATE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_UPDATE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> CLEAR_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]
static inline bool GET_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> CLEAR_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_STOP_RUNN_ON_XSTOP,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]
static inline bool GET_OPCG_REG0_STOP_RUNN_ON_XSTOP(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_STOP_RUNN_ON_XSTOP>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_STOP_RUNN_ON_XSTOP chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_STOP_RUNN_ON_XSTOP]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> CLEAR_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_OPCG_STARTS_BIST]

//>> GET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_OPCG_STARTS_BIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> GET_[OPCG_REG0_OPCG_STARTS_BIST]
static inline bool GET_OPCG_REG0_OPCG_STARTS_BIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_OPCG_STARTS_BIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_OPCG_STARTS_BIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_OPCG_STARTS_BIST]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.setBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> CLEAR_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& CLEAR_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.clearBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> GET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_RUNN_HLD_DLY_EN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> GET_[OPCG_REG0_RUNN_HLD_DLY_EN]
static inline bool GET_OPCG_REG0_RUNN_HLD_DLY_EN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.getBit<OPCG_REG0_RUNN_HLD_DLY_EN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access OPCG_REG0_RUNN_HLD_DLY_EN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_RUNN_HLD_DLY_EN]

//>> SET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_LOOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_LOOP_COUNT]

//>> SET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& SET_OPCG_REG0_LOOP_COUNT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return o_data.insertFromRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[OPCG_REG0_LOOP_COUNT]

//>> GET_[OPCG_REG0_LOOP_COUNT]
static inline fapi2::buffer<uint64_t>& GET_OPCG_REG0_LOOP_COUNT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(OPCG_REG0));
#endif
    return i_data.extractToRight<OPCG_REG0_LOOP_COUNT,
           OPCG_REG0_LOOP_COUNT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access OPCG_REG0_LOOP_COUNT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[OPCG_REG0_LOOP_COUNT]

//>> PREP_[QME_DORP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_DORP(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DORP;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_DORP]

//>> GET_[QME_DORP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_DORP(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_DORP;
#endif
    return fapi2::getScom(i_target, QME_DORP, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_DORP]

//>> PUT_[QME_DORP]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_DORP(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return fapi2::putScom(i_target, QME_DORP, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_DORP]


//>> SET_[QME_DORP_QUOTIENT]
static inline fapi2::buffer<uint64_t>& SET_QME_DORP_QUOTIENT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return o_data.insertFromRight<QME_DORP_QUOTIENT,
           QME_DORP_QUOTIENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DORP_QUOTIENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DORP_QUOTIENT]

//>> SET_[QME_DORP_QUOTIENT]
static inline fapi2::buffer<uint64_t>& SET_QME_DORP_QUOTIENT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return o_data.insertFromRight<QME_DORP_QUOTIENT,
           QME_DORP_QUOTIENT_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DORP_QUOTIENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DORP_QUOTIENT]

//>> GET_[QME_DORP_QUOTIENT]
static inline fapi2::buffer<uint64_t>& GET_QME_DORP_QUOTIENT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return i_data.extractToRight<QME_DORP_QUOTIENT,
           QME_DORP_QUOTIENT_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DORP_QUOTIENT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DORP_QUOTIENT]

//>> SET_[QME_DORP_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_QME_DORP_REMAINDER(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return o_data.insertFromRight<QME_DORP_REMAINDER,
           QME_DORP_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_DORP_REMAINDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DORP_REMAINDER]

//>> SET_[QME_DORP_REMAINDER]
static inline fapi2::buffer<uint64_t>& SET_QME_DORP_REMAINDER(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return o_data.insertFromRight<QME_DORP_REMAINDER,
           QME_DORP_REMAINDER_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_DORP_REMAINDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_DORP_REMAINDER]

//>> GET_[QME_DORP_REMAINDER]
static inline fapi2::buffer<uint64_t>& GET_QME_DORP_REMAINDER(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_DORP));
#endif
    return i_data.extractToRight<QME_DORP_REMAINDER,
           QME_DORP_REMAINDER_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_DORP_REMAINDER chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_DORP_REMAINDER]

//>> PREP_[QME_RVCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_RVCR(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RVCR;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_RVCR]

//>> GET_[QME_RVCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_RVCR(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_RVCR;
#endif
    return fapi2::getScom(i_target, QME_RVCR, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_RVCR]

//>> PUT_[QME_RVCR]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_RVCR(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_RVCR));
#endif
    return fapi2::putScom(i_target, QME_RVCR, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_RVCR]


//>> SET_[QME_RVCR_RVID_VALUE]
static inline fapi2::buffer<uint64_t>& SET_QME_RVCR_RVID_VALUE(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RVCR));
#endif
    return o_data.insertFromRight<QME_RVCR_RVID_VALUE,
           QME_RVCR_RVID_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_RVCR_RVID_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RVCR_RVID_VALUE]

//>> SET_[QME_RVCR_RVID_VALUE]
static inline fapi2::buffer<uint64_t>& SET_QME_RVCR_RVID_VALUE(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RVCR));
#endif
    return o_data.insertFromRight<QME_RVCR_RVID_VALUE,
           QME_RVCR_RVID_VALUE_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_RVCR_RVID_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_RVCR_RVID_VALUE]

//>> GET_[QME_RVCR_RVID_VALUE]
static inline fapi2::buffer<uint64_t>& GET_QME_RVCR_RVID_VALUE(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_RVCR));
#endif
    return i_data.extractToRight<QME_RVCR_RVID_VALUE,
           QME_RVCR_RVID_VALUE_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_RVCR_RVID_VALUE chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_RVCR_RVID_VALUE]

//>> PREP_[QME_SCOM_XIVDR28]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIVDR28(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR28;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIVDR28]

//>> GET_[QME_SCOM_XIVDR28]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIVDR28(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR28;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIVDR28, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIVDR28]

//>> PUT_[QME_SCOM_XIVDR28]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIVDR28(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIVDR28, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIVDR28]


//>> SET_[QME_SCOM_XIVDR28_8]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR28_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR28_8,
           QME_SCOM_XIVDR28_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR28_8]

//>> SET_[QME_SCOM_XIVDR28_8]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR28_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR28_8,
           QME_SCOM_XIVDR28_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR28_8]

//>> GET_[QME_SCOM_XIVDR28_8]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR28_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR28_8,
           QME_SCOM_XIVDR28_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR28_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR28_8]

//>> SET_[QME_SCOM_XIVDR28_9]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR28_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR28_9,
           QME_SCOM_XIVDR28_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR28_9]

//>> SET_[QME_SCOM_XIVDR28_9]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR28_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR28_9,
           QME_SCOM_XIVDR28_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR28_9]

//>> GET_[QME_SCOM_XIVDR28_9]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR28_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR28));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR28_9,
           QME_SCOM_XIVDR28_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR28_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR28_9]

//>> PREP_[QME_SCOM_XIVDR8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCOM_XIVDR8(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR8;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCOM_XIVDR8]

//>> GET_[QME_SCOM_XIVDR8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCOM_XIVDR8(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCOM_XIVDR8;
#endif
    return fapi2::getScom(i_target, QME_SCOM_XIVDR8, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCOM_XIVDR8]

//>> PUT_[QME_SCOM_XIVDR8]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCOM_XIVDR8(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return fapi2::putScom(i_target, QME_SCOM_XIVDR8, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCOM_XIVDR8]


//>> SET_[QME_SCOM_XIVDR8_8]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR8_8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR8_8,
           QME_SCOM_XIVDR8_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR8_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR8_8]

//>> SET_[QME_SCOM_XIVDR8_8]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR8_8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR8_8,
           QME_SCOM_XIVDR8_8_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR8_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR8_8]

//>> GET_[QME_SCOM_XIVDR8_8]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR8_8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR8_8,
           QME_SCOM_XIVDR8_8_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR8_8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR8_8]

//>> SET_[QME_SCOM_XIVDR8_9]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR8_9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR8_9,
           QME_SCOM_XIVDR8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCOM_XIVDR8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR8_9]

//>> SET_[QME_SCOM_XIVDR8_9]
static inline fapi2::buffer<uint64_t>& SET_QME_SCOM_XIVDR8_9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return o_data.insertFromRight<QME_SCOM_XIVDR8_9,
           QME_SCOM_XIVDR8_9_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCOM_XIVDR8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCOM_XIVDR8_9]

//>> GET_[QME_SCOM_XIVDR8_9]
static inline fapi2::buffer<uint64_t>& GET_QME_SCOM_XIVDR8_9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCOM_XIVDR8));
#endif
    return i_data.extractToRight<QME_SCOM_XIVDR8_9,
           QME_SCOM_XIVDR8_9_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCOM_XIVDR8_9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCOM_XIVDR8_9]

//>> PREP_[QME_SCRA_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_QME_SCRA_RW(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRA_RW;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[QME_SCRA_RW]

//>> GET_[QME_SCRA_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_QME_SCRA_RW(const fapi2::Target<K, M, V>& i_target, fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = QME_SCRA_RW;
#endif
    return fapi2::getScom(i_target, QME_SCRA_RW, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[QME_SCRA_RW]

//>> PUT_[QME_SCRA_RW]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_QME_SCRA_RW(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(QME_SCRA_RW, QME_SCRA_WO_CLEAR, QME_SCRA_WO_OR));
#endif
    return fapi2::putScom(i_target, QME_SCRA_RW, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[QME_SCRA_RW]

//>> SET_[QME_SCRA_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCRA_DATA(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRA_RW, QME_SCRA_WO_CLEAR, QME_SCRA_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCRA_DATA,
           QME_SCRA_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access QME_SCRA_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCRA_DATA]

//>> SET_[QME_SCRA_DATA]
static inline fapi2::buffer<uint64_t>& SET_QME_SCRA_DATA(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRA_RW, QME_SCRA_WO_CLEAR, QME_SCRA_WO_OR));
#endif
    return o_data.insertFromRight<QME_SCRA_DATA,
           QME_SCRA_DATA_LEN>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access QME_SCRA_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[QME_SCRA_DATA]

//>> GET_[QME_SCRA_DATA]
static inline fapi2::buffer<uint64_t>& GET_QME_SCRA_DATA(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(QME_SCRA_RW, QME_SCRA_WO_CLEAR, QME_SCRA_WO_OR));
#endif
    return i_data.extractToRight<QME_SCRA_DATA,
           QME_SCRA_DATA_LEN>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access QME_SCRA_DATA chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[QME_SCRA_DATA]

//>> PREP_[SCAN_REGION_TYPE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PREP_SCAN_REGION_TYPE(const fapi2::Target<K, M, V>& i_target)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_REGION_TYPE;
#endif
    return fapi2::current_err;
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PREP_[SCAN_REGION_TYPE]

//>> GET_[SCAN_REGION_TYPE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode GET_SCAN_REGION_TYPE(const fapi2::Target<K, M, V>& i_target,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    scomt::last_scom = SCAN_REGION_TYPE;
#endif
    return fapi2::getScom(i_target, SCAN_REGION_TYPE, o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< GET_[SCAN_REGION_TYPE]

//>> PUT_[SCAN_REGION_TYPE]
template< fapi2::TargetType K, fapi2::MulticastType M, typename V >
static inline fapi2::ReturnCode PUT_SCAN_REGION_TYPE(const fapi2::Target<K, M, V>& i_target, const uint64_t i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::init(i_target));
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return fapi2::putScom(i_target, SCAN_REGION_TYPE, i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    return fapi2::current_err;
#endif
}
//<< PUT_[SCAN_REGION_TYPE]


//>> SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SYSTEM_FAST_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SYSTEM_FAST_INIT,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SYSTEM_FAST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> CLEAR_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SYSTEM_FAST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> GET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SYSTEM_FAST_INIT,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> GET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]
static inline bool GET_SCAN_REGION_TYPE_SYSTEM_FAST_INIT(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SYSTEM_FAST_INIT>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SYSTEM_FAST_INIT chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SYSTEM_FAST_INIT]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_PARALLEL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_PARALLEL_SCAN,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_PARALLEL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> CLEAR_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_PARALLEL_SCAN(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_PARALLEL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> GET_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_PARALLEL_SCAN(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_PARALLEL_SCAN,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> GET_[SCAN_REGION_TYPE_PARALLEL_SCAN]
static inline bool GET_SCAN_REGION_TYPE_PARALLEL_SCAN(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_PARALLEL_SCAN>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_PARALLEL_SCAN]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> CLEAR_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> GET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> GET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]
static inline bool GET_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR chip: %x, ec: %x", scomt::chip,
             scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_VITL(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_VITL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_VITL(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_VITL,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_VITL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_VITL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_VITL(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_VITL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_VITL(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_VITL,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_VITL(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_VITL>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_VITL chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_VITL]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_PERV(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_PERV,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_PERV(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_PERV(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_PERV,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_PERV(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_PERV>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_PERV chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_PERV]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT1,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT1,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT1(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT1>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT1 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT1]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT2,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT2,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT2(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT2>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT2 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT2]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT3,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT3,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT3(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT3>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT3 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT3]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT4,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT4,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT4(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT4>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT4 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT4]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT5,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT5,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT5(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT5>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT5 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT5]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT6,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT6,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT6(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT6>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT6 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT6]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT7,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT7,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT7(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT7>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT7 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT7]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT8,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT8,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT8(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT8>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT8 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT8]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT9,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT9,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT9(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT9>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT9 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT9]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT10,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT10,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT10(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT10>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT10 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT10]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT11,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT11,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT11(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT11>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT11 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT11]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT12,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT12,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT12(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT12>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT12 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT12]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT13,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT13,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT13(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT13>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT13 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT13]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT14,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_REGION_UNIT14,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]
static inline bool GET_SCAN_REGION_TYPE_SCAN_REGION_UNIT14(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_REGION_UNIT14>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_REGION_UNIT14 chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_REGION_UNIT14]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_FUNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_FUNC,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_FUNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_FUNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_FUNC,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_FUNC(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_FUNC>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FUNC chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_FUNC]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CFG(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CFG(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CFG,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_CFG(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_CFG(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_CFG,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_CFG(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_CFG>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CFG chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CFG]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REGF(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_REGF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REGF(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_REGF,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REGF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_REGF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_REGF(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_REGF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_REGF(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_REGF,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_REGF(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_REGF>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REGF chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_REGF]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_LBIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_LBIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_LBIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_LBIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_LBIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_LBIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_LBIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_LBIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_LBIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_ABIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_ABIST,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_ABIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_ABIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_ABIST,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_ABIST(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_ABIST>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_ABIST chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_ABIST]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REPR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_REPR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REPR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_REPR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_REPR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_REPR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_REPR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_REPR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_REPR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_REPR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_REPR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_REPR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_REPR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_REPR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_TIME(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_TIME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_TIME(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_TIME,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_TIME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_TIME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_TIME(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_TIME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_TIME(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_TIME,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_TIME(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_TIME>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_TIME chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_TIME]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_BNDY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_BNDY,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_BNDY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_BNDY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_BNDY,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_BNDY(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_BNDY>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_BNDY chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_BNDY]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FARR(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_FARR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FARR(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_FARR,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_FARR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_FARR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_FARR(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_FARR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_FARR(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_FARR,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_FARR(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_FARR>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_FARR chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_FARR]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CMSK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_CMSK,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_CMSK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_CMSK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_CMSK,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_CMSK(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_CMSK>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_CMSK chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_CMSK]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_INEX(fapi2::buffer<uint64_t>& i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_INEX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("0:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_INEX(const uint64_t i_data,
        fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.insertFromRight<SCAN_REGION_TYPE_SCAN_TYPE_INEX,
           1>(i_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("1:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>> SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline fapi2::buffer<uint64_t>& SET_SCAN_REGION_TYPE_SCAN_TYPE_INEX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.setBit<SCAN_REGION_TYPE_SCAN_TYPE_INEX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("2:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< SET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>> CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline fapi2::buffer<uint64_t>& CLEAR_SCAN_REGION_TYPE_SCAN_TYPE_INEX(fapi2::buffer<uint64_t>& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return o_data.clearBit<SCAN_REGION_TYPE_SCAN_TYPE_INEX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("3:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return o_data;
#endif
}
//<< CLEAR_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline fapi2::buffer<uint64_t>& GET_SCAN_REGION_TYPE_SCAN_TYPE_INEX(fapi2::buffer<uint64_t>& i_data,
        uint64_t& o_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.extractToRight<SCAN_REGION_TYPE_SCAN_TYPE_INEX,
           1>(o_data);
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("4:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>> GET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]
static inline bool GET_SCAN_REGION_TYPE_SCAN_TYPE_INEX(fapi2::buffer<uint64_t>& i_data)
{
#ifdef SCOM_CHECKING
    FAPI_TRY(scomt::chkReg(SCAN_REGION_TYPE));
#endif
    return i_data.getBit<SCAN_REGION_TYPE_SCAN_TYPE_INEX>();
#ifdef SCOM_CHECKING
fapi_try_exit:
    FAPI_ERR("5:scom_eq Invalid dial access SCAN_REGION_TYPE_SCAN_TYPE_INEX chip: %x, ec: %x", scomt::chip, scomt::ec);
    return i_data;
#endif
}
//<< GET_[SCAN_REGION_TYPE_SCAN_TYPE_INEX]

//>>THE END<<

#ifndef __PPE_HCODE__
}
}

#endif
#endif
